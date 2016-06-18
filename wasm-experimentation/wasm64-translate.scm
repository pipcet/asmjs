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
    (list 'i32.store8 (xlat-expr (cadr lhs) f-labels)
          (xlat-expr rhs f-labels)))
   ((memq (car lhs) '(i16.mem i16.mem_u))
    (list 'i32.store16 (xlat-expr (cadr lhs) f-labels)
          (xlat-expr rhs f-labels)))
   ((memq (car lhs) '(i32.mem i32.mem_u))
    (list 'i32.store (xlat-expr (cadr lhs) f-labels)
          (xlat-expr rhs f-labels)))
   ((memq (car lhs) '(i64.mem i64.mem_u))
    (list 'i64.store (xlat-expr (cadr lhs) f-labels)
          (xlat-expr rhs f-labels)))
   ((memq (car lhs) '(f32.mem))
    (list 'f32.store (xlat-expr (cadr lhs) f-labels)
          (list 'f32.demote_f64 (xlat-expr rhs f-labels))))
   ((memq (car lhs) '(f64.mem))
    (list 'f64.store (xlat-expr (cadr lhs) f-labels)
          (xlat-expr rhs f-labels)))
   ((memq (car lhs) '(get_local))
    (list 'set_local (cadr lhs)
          (xlat-expr rhs f-labels)))
   (#t
    (error "argh %S" lhs))))

(define (i8.mem_u e)
  `(i32.load8_u ,e))

(define (i16.mem_u e)
  `(i32.load16_u ,e))

(define (i32.mem_u e)
  `(i32.load ,e))

(define (i64.mem_u e)
  `(i64.load ,e))

(define (i8.mem e)
  `(i32.load8 ,e))

(define (i16.mem e)
  `(i32.load16 ,e))

(define (i32.mem e)
  `(i32.load ,e))

(define (i64.mem e)
  `(i64.load ,e))

(define (f32.mem e)
  `(f64.promote_f32 (f32.load ,e)))

(define (f64.mem e)
  `(f64.load ,e))


(define (i32.neg e)
  `(i32.sub (i32.const 0) ,e))

(define (i32.not e)
  `(i32.xor (i32.const -1) ,e))

(define (i32.eq a b)
  `(f64.eq ,a ,b))
(define (i32.ne a b)
  `(f64.ne ,a ,b))
(define (i32.le a b)
  `(f64.le ,a ,b))
(define (i32.ge a b)
  `(f64.ge ,a ,b))
(define (i32.lt a b)
  `(f64.lt ,a ,b))
(define (i32.gt a b)
  `(f64.gt ,a ,b))

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
   ((memq (car e) '(i32.add i32.sub i32.mul_u i32.mul_s i32.div_u i32.div_s i32.and i32.or i32.gt_u i32.ge_u i32.shr_u i32.ne))
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
                (emblocken (reverse (cons '((return (i64.const 0))) f))
                           block-labels
                           (cons 'br_table
                                 (append (reverse block-labels) (list switch-default-label
                                                                      `(i32.wrap_i64 (get_local $dpc)))))
                           (list while-in-label while-out-label)))
          (list 'return '(i64.const 0)))
    restore)))

;; XXX a jump to the first function will go wrong because of the
;; off-by-one hack below.

(define (xlat-fpswitch fpswitch uniq)
  (let ((switch-default-label
         (string->symbol
          (string-append "$switch-default$" (uniq))))
        (block-labels
         (gen-block-labels (length fpswitch) "$block$" uniq)))
    (list 'block switch-default-label
          (emblocken (reverse fpswitch)
                     block-labels
                     (cons 'br_table
                           (append (reverse block-labels) (list switch-default-label
                                                                (list 'i64.shr_u '(i64.sub (get_local $pc0) (i64.const 288230376151720192)) '(i64.const 8))))) ;; XXX for the constant
                     (list '() '()))
          (list 'return '(i64.const 0)))
    ))

(define (emblocken2 rev-f labels s f-labels)
  (let* ((res s))
    (while (not (null? rev-f))
           (set! res `(block ,(car labels) ,res ,@(xlat-block (car rev-f) f-labels)))
           (set! rev-f (cdr rev-f))
           (set! labels (cdr labels)))
    res))

(define (emblocken rev-f labels s f-labels)
  (if (null? labels)
      (if (null? rev-f) s (error "too much code"))
      (append `(block ,(car labels) ,(emblocken (cdr rev-f) (cdr labels) s f-labels))
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

;; (if #f (write (split-blocks '((call_import $cp (i32.const 42))
;;                               (call_import $cp (i32.const 43))
;;                               (jump)
;;                               (throw)
;;                               (call_import $cp (i32.const 44))
;;                               (call_import $cp (i32.const 45))
;;                               (return)))))

;; (if #f (write-module (split-blocks '((call_import $cp (i32.const 42))
;;                               (call_import $cp (i32.const 43))
;;                               (jump)
;;                               (throw)
;;                               (call_import $cp (i32.const 44))
;;                               (call_import $cp (i32.const 45))
;;                               (return)))))

;; (if #f (write (split-blocks '((call_import $cp (i32.const 42))
;;                               (call_import $cp (i32.const 43))
;;                               (call_import $cp (i32.const 44))
;;                               (call_import $cp (i32.const 45))
;;                               (return)))))

(define (make-module fpswitch fdefs uniq)
  `(module
    (memory 1024 1024)
    (import $cp "console" "print" (param i64))
    (import $extcall "thinthin" "extcall" (param i64 i64 i64 i64) (result i64))
    (import $indcall "thinthin" "indcall" (param i64 i64 i64 i64 i64 i64) (result i64))
    (import $eh_return "thinthin" "eh_return" (param i64 i64 i64) (result i64))
    (func "f_0x0" $f_0x0 (param $dpc i64) (param $sp1 i64) (param $r0 i64) (param $r1 i64) (param $pc0 i64) (param $rpc i64) (result i64) (return (i64.const 0)))
    ;;(func "peek" $peek (param $addr i64) (result i64) (return (i64.extend_u_i32 (i32.load8_u (i32.wrap_i64 (get_local $addr))))))
    ;;(func "poke" $poke (param $addr i64) (param $data i64) (i32.store8 (i32.wrap_i64 (get_local $addr)) (i32.wrap_i64 (get_local $data))))
    (func "shl" $shl (param $x i64) (param $count i64) (result i64) (if (i64.gt_u (get_local $count) (i64.const 63)) (then (return (i64.const 0)))) (return (i64.shl (get_local $x) (get_local $count))))
    (func "shr_s" $shr_s (param $x i64) (param $count i64) (result i64) (if (i64.gt_u (get_local $count) (i64.const 63)) (then (set_local $count (i64.const 63)))) (return (i64.shr_s (get_local $x) (get_local $count))))
    (func "shr_u" $shr_u (param $x i64) (param $count i64) (result i64) (if (i64.gt_u (get_local $count) (i64.const 63)) (then (return (i64.const 0)))) (return (i64.shr_u (get_local $x) (get_local $count))))
    (func "i64_load" $i64_load (param $addr i32) (result i64) (return (i64.reinterpret_f64 (f64.load (get_local $addr)))))
    (func "i64_load32_s" $i64_load32_s (param $addr i32) (result i64) (return (i64.extend_s_i32 (i32.load (get_local $addr)))))
    (func "i64_load_i32_s" $i64_load_i32 (param $addr i32) (result i64) (return (i64.extend_s_i32 (i32.load (get_local $addr)))))
    (func "i64_load16_s" $i64_load16_s (param $addr i32) (result i64) (return (i64.extend_s_i16 (i32.load16_s (get_local $addr)))))
    (func "i64_load8_s" $i64_load8_s (param $addr i32) (result i64) (return (i64.extend_s_i8 (i32.load8_s (get_local $addr)))))
    (func "i64_load32_u" $i64_load32_u (param $addr i32) (result i64) (return (i64.extend_u_i32 (i32.load (get_local $addr)))))
    (func "i64_load16_u" $i64_load16_u (param $addr i32) (result i64) (return (i64.extend_u_i16 (i32.load16_u (get_local $addr)))))
    (func "i64_load8_u" $i64_load8_u (param $addr i32) (result i64) (return (i64.extend_u_i8 (i32.load8_u (get_local $addr)))))
    (func "i64_store" $i64_store (param $addr i32) (param $v i64) (f64.store (get_local $addr) (f64.reinterpret_i64 (get_local $v))))
    (func "i64_store_i32" $i64_store_i32 (param $addr i32) (param $v i64) (i32.store (get_local $addr) (i32.wrap_i64 (get_local $v))))
    (func "i64_store32" $i64_store32 (param $addr i32) (param $v i64) (i32.store (get_local $addr) (i32.wrap_i64 (get_local $v))))
    (func "i64_store16" $i64_store16 (param $addr i32) (param $v i64) (i32.store16 (get_local $addr) (i32.wrap_i64 (get_local $v))))
    (func "i64_store8" $i64_store8 (param $addr i32) (param $v i64) (i32.store8 (get_local $addr) (i32.wrap_i64 (get_local $v))))
    (func "f_indcall" $f_indcall (param $dpc i64) (param $sp1 i64) (param $r0 i64) (param $r1 i64) (param $rpc i64) (param $pc0 i64) (result i64)
          (return (call_import $indcall (get_local $dpc) (get_local $sp1) (get_local $r0) (get_local $r1) (get_local $rpc) (get_local $pc0)))
          ;;,(xlat-fpswitch (split-blocks fpswitch) uniq)
          (return (i64.const 3)))
    ,@fdefs
    (export "memory" memory)))

(define (string-delete a &rest args)
  (string-replace a " " ""))

(define (1+ x) (+ 1 x))

(define (1- x) (- x 1))

(define (hex x)
  (string->number (string-replace x " " "") 16))

(write (let* ((nuclear #t) ;; nuclear option for debugging, trace all calls.
              (ucnt 0)
              (uniq (lambda ()
                      (set! ucnt (1+ ucnt))
                      (number->string ucnt)))
              (sexp (eval (read)))
              (fpswitch (car sexp))
              (fdefs (cdr sexp)))
         (make-module fpswitch (map (lambda (fdef)
                            (let* ((str (string-delete (car fdef) #\ 0))
                                   (sym (string->symbol (string-append "$" str))))
                              (list 'func str sym '(param $dpc i64) '(param $sp1 i64) '(param $r0 i64) '(param $r1 i64) '(param $rpc i64) '(param $pc0 i64) '(result i64) '(local $sp i64) '(local $fp i64) '(local $r2 i64) '(local $r3 i64) '(local $r4 i64) '(local $r5 i64) '(local $r6 i64) '(local $r7 i64) '(local $i0 i64) '(local $i1 i64) '(local $i2 i64) '(local $i3 i64) '(local $i4 i64) '(local $i5 i64) '(local $i6 i64) '(local $i7 i64) '(local $f0 f64) '(local $f1 f64) '(local $f2 f64) '(local $f3 f64) '(local $f4 f64) '(local $f5 f64) '(local $f6 f64) '(local $f7 f64) '(local $rp i64) (xlat-function (split-blocks (if nuclear (cons '(call_import $cp (get_local $pc0)) (cddr fdef)) (cddr fdef))) uniq (cadr fdef)))))
              fdefs) uniq)))

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
