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

(define (xlat-set lhs rhs f-labels)
  (cond
   ((eq? lhs '$rv)
    (list 'i32.store '(i32.const 4096) (xlat-expr rhs f-labels)))
   ((not (list? lhs))
    (list 'set_local lhs (xlat-expr rhs f-labels)))
   ((eq? (car lhs) 'mem)
    (list 'i32.store (xlat-expr (cadr lhs) f-labels)
          (xlat-expr rhs f-labels)))
   (#t
    (error))))

(define (xlat-expr e f-labels)
  (cond
   ((number? e)
    (list 'i32.const e))
   ((eq? e '$rv)
    (xlat-expr (list 'mem '(i32.const 4096))))
   ((not (list? e))
    (list 'get_local e))
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
   ((eq? (car e) 'if)
    (cons 'if (map (lambda (x) (xlat-expr x f-labels)) (cdr e))))
   ((eq? (car e) 'then)
    (cons 'then (map (lambda (x) (xlat-expr x f-labels)) (cdr e))))
   ((eq? (car e) 'else)
    (cons 'else (map (lambda (x) (xlat-expr x f-labels)) (cdr e))))
   ((eq? (car e) 'mem)
    (list 'i32.load (xlat-expr (cadr e) f-labels)))
   (#t
    e)))

(define (xlat-block b f-labels )
  (map (lambda (e) (xlat-expr e f-labels)) b))

(define (xlat-function f uniq)
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
    (list 'loop while-out-label while-in-label
          (list 'block switch-default-label
                (emblocken (reverse (cons '((return (i32.const 0))) f))
                           block-labels
                           (cons 'br_table
                                 (append (reverse block-labels) (list switch-default-label
                                                                      (list 'get_local '$dpc))))
                           (list while-in-label while-out-label)))
          
          (list 'return '(i32.const 0)))
          ))

(define (write-module f)
  (let* ((ucnt 0)
         (uniq (lambda ()
                 (set! ucnt (1+ ucnt))
                 (number->string ucnt))))
    (write (list 'module
                 (list 'import '$cp "console" "print" '(param i32))
                 (list 'func "x" '$x '(param $dpc i32) '(param $sp i32) '(param $r0 i32) '(param $r1 i32) '(param $pc0 i32) '(param $rpc i32) (xlat-function f uniq))))))

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
    (if (null? (car r)) (cadr r)
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

(define (make-module fdef)
  (list 'module
        (list 'memory 32 32)
        (list 'import '$cp "console" "print" '(param i32))
        `(func $peek (param $addr i32) (i32.load (get_local $addr)))
        fdef
        (list 'export "memory" 'memory)
        ))

(write (let* ((ucnt 0)
              (uniq (lambda ()
                      (set! ucnt (1+ ucnt))
                      (number->string ucnt))))
         (car (map make-module (map (lambda (fdef)
                (let* ((str (string-delete (car fdef) #\ 0))
                       (sym (string->symbol (string-append "$" str))))
                  (list 'func str sym '(param $dpc i32) '(param $sp1 i32) '(param $r0 i32) '(param $r1 i32) '(param $rpc i32) '(param $pc0 i32) '(result i32) '(local $sp i32) '(local $fp i32) '(local $r2 i32) '(local $r3 i32) '(local $r4 i32) '(local $r5 i32) '(local $r6 i32) '(local $r7 i32) '(local $i0 i32) '(local $i1 i32) '(local $i2 i32) '(local $i3 i32) '(local $i4 i32) '(local $i5 i32) '(local $i6 i32) '(local $i7 i32) '(local $f0 f64) '(local $f1 f64) '(local $f2 f64) '(local $f3 f64) '(local $f4 f64) '(local $f5 f64) '(local $f6 f64) '(local $f7 f64) (xlat-function (split-blocks (cdr fdef)) uniq))))
              (eval (read) (interaction-environment)))))))

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
