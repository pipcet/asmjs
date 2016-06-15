(define (block-n uniq n s)
  (let ((u (uniq)))
    (if (= n 0) s
        (list 'block (string->symbol
                      (string-append "$" (number->string u)
                                     "$" (number->string n)))
              (block-n uniq (1- n) s)))))


(define (gen-block-labels n prefix uniq)
  (if (= n 0)
      '()
      (cons (string->symbol
             (string-append prefix (uniq)))
            (gen-block-labels (1- n) prefix uniq))))

(define (thread-reg-addr reg)
  (cond
   ((eq? reg '$rv) 4096)
   ((eq? reg '$a0) 4104)
   ((eq? reg '$a1) 4112)
   ((eq? reg '$a2) 4120)
   ((eq? reg '$a3) 4128)
   ((eq? reg '$tp) 4136)))

(define (xlat-set lhs rhs f-labels)
  (cond
   ((memq lhs '($rv $a0 $a1 $a2 $a3 $tp))
    (list 'i32.store `(i32.const ,(thread-reg-addr lhs)) (xlat-expr rhs f-labels)))
   ((not (list? lhs))
    (list 'set_local lhs (xlat-expr rhs f-labels)))
   ((memq (car lhs) '(i8.mem i8.mem_u))
    (list 'i8.store (xlat-expr (cadr lhs) f-labels)
          (xlat-expr rhs f-labels)))
   ((memq (car lhs) '(i16.mem i16.mem_u))
    (list 'i16.store (xlat-expr (cadr lhs) f-labels)
          (xlat-expr rhs f-labels)))
   ((memq (car lhs) '(i32.mem i32.mem_u))
    (list 'i32.store (xlat-expr (cadr lhs) f-labels)
          (xlat-expr rhs f-labels)))
   ((memq (car lhs) '(i64.mem i64.mem_u))
    (list 'i64.store (xlat-expr (cadr lhs) f-labels)
          (xlat-expr rhs f-labels)))
   (#t
    (error))))

(define (i32.neg e)
  `(i32.sub (i32.const 0) ,e))

(define (i32.not e)
  `(i32.xor (i32.const -1) ,e))

(define (xlat-expr e f-labels)
  (cond
   ((number? e)
    (list 'i32.const e))
   ((eq? e '$rv)
    (xlat-expr (list 'i32.mem '(i32.const 4096)) f-labels))
   ((not (list? e))
    (list 'get_local e))
   ((and (eq? (car e) 'br) (eq? (cadr e) '$mainloop))
    `(br ,(cadr f-labels)))
   ((eq? (car e) 'return)
    (cons 'return (map (lambda (x) (xlat-expr x f-labels)) (cdr e))))
   ((eq? (car e) 'jump)
    (list 'br (car f-labels)))
   ((eq? (car e) 'throw)
    (list 'br (cadr f-labels)))
   ((eq? (car e) 'label)
    (list 'nop))
   ((eq? (car e) 'set)
    (xlat-set (cadr e) (caddr e) f-labels))
   ((memq (car e) '(i32.add i32.sub i32.mul_u i32.mul_s i32.div_u i32.div_s))
    (cons (car e) (map (lambda (x) (xlat-expr x f-labels)) (cdr e))))
   ((eq? (car e) 'if)
    (cons 'if (map (lambda (x) (xlat-expr x f-labels)) (cdr e))))
   ((eq? (car e) 'then)
    (cons 'then (map (lambda (x) (xlat-expr x f-labels)) (cdr e))))
   ((eq? (car e) 'else)
    (cons 'else (map (lambda (x) (xlat-expr x f-labels)) (cdr e))))
   ((eq? (car e) 'i8.mem)
    (list 'i32.load8 (xlat-expr (cadr e) f-labels)))
   ((eq? (car e) 'i16.mem)
    (list 'i32.load16 (xlat-expr (cadr e) f-labels)))
   ((eq? (car e) 'i32.mem)
    (list 'i32.load (xlat-expr (cadr e) f-labels)))
   ((eq? (car e) 'i8.mem_u)
    (list 'i32.load8_u (xlat-expr (cadr e) f-labels)))
   ((eq? (car e) 'i16.mem_u)
    (list 'i32.load16_u (xlat-expr (cadr e) f-labels)))
   ((eq? (car e) 'i32.mem_u)
    (list 'i32.load (xlat-expr (cadr e) f-labels)))
   ((eq? (car e) 'i32.not)
    `(i32.xor ,e (i32.const -1)))
   ((eq? (car e) 'i32.neg)
    `(i32.sub (i32.const 0) ,e))
   (#t
    e)))

(define (xlat-block b f-labels )
  (map (lambda (e) (xlat-expr e f-labels)) b))

(define (xlat-function f uniq restore)
  (let ((while-out-label
         (string->symbol
          (string-append "$while-out$" (uniq))))
        (while-in-label
         (string->symbol
          (string-append "$while-in$" (uniq))))
        (switch-default-label
         (string->symbol
          (string-append "$switch-default$" (uniq))))
        (block-labels
         (gen-block-labels (1+ (length f)) "$block$" uniq)))
    (list 'block
    (list 'loop while-out-label while-in-label
          (list 'block switch-default-label
                (emblocken (reverse (cons '((return (i32.const 0))) f))
                           block-labels
                           (cons 'br_table
                                 (append (reverse block-labels) (list switch-default-label
                                                                      (list 'get_local '$dpc))))
                           (list while-in-label while-out-label)))
          (list 'return '(i32.const 0)))
    restore)))

(define (emblocken rev-f labels s f-labels)
  (if (null? labels)
      s
      (append (list 'block (car labels) (emblocken (cdr rev-f) (cdr labels) s f-labels))
              (xlat-block (car rev-f) f-labels))))

;; (write-module '(((call_import $cp (i32.const 42)))
;;                 ((call_import $cp (i32.const 43)))
;;                 ((call_import $cp (i32.const 44)))
;;                 ((call_import $cp (i32.const 45)))
;;                 ((return))
;;                 ((jump))))

(define (scan-for-jump x)
  (if (and (list? x) (not (null? x)))
      (or (scan-for-jump (car x)) (scan-for-jump (cdr x)))
      (or ;;(eq? x 'jump) (eq? x 'throw)
       (eq? x 'label))))

(define (split-blocks-r f)
  (if (null? f) (list '() '())
      (let* ((h (car f))
             (rest (cdr f))
             (r (split-blocks-r rest))
             (blocks (car r))
             (current-block (cadr r)))
        (if (scan-for-jump h)
            (list (cons (cons h current-block) blocks) '())
            (list blocks (cons h current-block))))))

(define (split-blocks-2 f)
  (let* ((r (split-blocks-r (reverse f))))
    (if (null? (cadr r)) (car r)
        (cons (cadr r) (car r)))))

(define (split-blocks f)
  (reverse (map reverse (split-blocks-2 f))))

(if #f (write (split-blocks '((call_import $cp (i32.const 42))
                              (call_import $cp (i32.const 43))
                              (jump)
                              (throw)
                              (call_import $cp (i32.const 44))
                              (call_import $cp (i32.const 45))
                              (return)))))

(if #f (write-module (split-blocks '((call_import $cp (i32.const 42))
                              (call_import $cp (i32.const 43))
                              (jump)
                              (throw)
                              (call_import $cp (i32.const 44))
                              (call_import $cp (i32.const 45))
                              (return)))))

(if #f (write (split-blocks '((call_import $cp (i32.const 42))
                              (call_import $cp (i32.const 43))
                              (call_import $cp (i32.const 44))
                              (call_import $cp (i32.const 45))
                              (return)))))

(define (make-module fdefs)
  `(module
    (memory 32 32)
    (import $cp "console" "print" (param i32))
    (import $extcall "thinthin" "extcall" (param i32 i32 i32 i32) (result i32))
    (import $indcall "thinthin" "indcall" (param i32 i32 i32 i32 i32 i32) (result i32))
    (func "peek" $peek (param $addr i32) (result i32) (return (i32.load8_u (get_local $addr))))
    (func "poke" $poke (param $addr i32) (param $data i32) (i32.store8 (get_local $addr) (get_local $data)))
    ,@fdefs
    (export "memory" memory)))

(write (let* ((ucnt 0)
              (uniq (lambda ()
                      (set! ucnt (1+ ucnt))
                      (number->string ucnt))))
         (make-module (map (lambda (fdef)
                            (let* ((str (string-delete (car fdef) #\ 0))
                                   (sym (string->symbol (string-append "$" str))))
                              (list 'func str sym '(param $dpc i32) '(param $sp1 i32) '(param $r0 i32) '(param $r1 i32) '(param $rpc i32) '(param $pc0 i32) '(result i32) '(local $sp i32) '(local $fp i32) '(local $r2 i32) '(local $r3 i32) '(local $r4 i32) '(local $r5 i32) '(local $r6 i32) '(local $r7 i32) '(local $i0 i32) '(local $i1 i32) '(local $i2 i32) '(local $i3 i32) '(local $i4 i32) '(local $i5 i32) '(local $i6 i32) '(local $i7 i32) '(local $f0 f64) '(local $f1 f64) '(local $f2 f64) '(local $f3 f64) '(local $f4 f64) '(local $f5 f64) '(local $f6 f64) '(local $f7 f64) '(local $rp i32) (xlat-function (split-blocks (cddr fdef)) uniq (cadr fdef)))))
              (eval (read) (interaction-environment))))))

;; (define (split-blocks f)
;;   (let ((blocks ())
;;         (current-block ()))
;;     (while (not (null? f))
;;            (let ((h (car f)))
;;              (set! current-block (append current-block (list h)))
;;              (when (scan-for-jump h)
;;                    (set! blocks (append blocks (list current-block)))
;;                    (set! current-block ()))
;;              (set! f (cdr f))))))
