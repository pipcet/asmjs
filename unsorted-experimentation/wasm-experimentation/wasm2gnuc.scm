(define i 0)
(define (gen-block) (set! i (+ 1 i)) (string-append "b" (number->string i)))
(define (gen-local) (set! i (+ 1 i)) (string-append "l" (number->string i)))

(define (parse-local context sexp)
  (let* ((ident (cadr sexp))
         (type (caddr sexp))
         (label (cdr (assoc ident (cadr context)))))
    (string-append (parse-type type) " " label " = 0;")))")

(define (parse-function context sexp)
  (let* ((params (filter (lambda (b) (eq? (car b) 'param)) sexp))
         (locals (filter (lambda (b) (eq? (car b) 'local)) sexp))
         (result (filter (lambda (b) (eq? (car b) 'result) sexp)))
         
                 ))))

(define (parse-block context sexp)
  (apply string-append (map (lambda (b) (parse context b)) sexp)))

(define (parse context sexp)
  (let* ((blocks (car context))
         (locals (cadr context))
         (opcode (car sexp)))
    (cond
     ((eq? opcode 'i32.const)
      (string-append "int32_t(" (number->string (cadr sexp)) ")"))
     ((eq? opcode 'i32.add)
      (string-append "int32_t((" (parse context (cadr sexp)) ")+("
                     (parse context (caddr sexp))))
     ((eq? opcode 'get_local)
      (cdr (assoc (cadr sexp) locals)))
     ((eq? opcode 'set_local)
      (string-append (cdr (assoc (cadr sexp) locals))
                     " = "
                     (parse context (caddr sexp))))
     ((eq? opcode 'br)
      (string-append "goto "
                     (cdr (assoc (cadr sexp) blocks))))
     ((eq? opcode 'block)
      (let* ((block (gen-block))
             (nblocks (cons (cons (cadr sexp) block) blocks))
             (ncontext (list nblocks locals)))
        (string-append "({"
                       (parse-block ncontext (cddr sexp))
                       ";"
                       block
                       ":"
                       ";"
                       "})")))
     ((eq? opcode 'loop)
      (let* ((in-block (gen-block))
             (out-block (gen-block))
             (nblocks (cons (cons (cadr sexp) in-block) (cons (cons (caddr sexp) out-block) blocks)))
             (ncontext (list nblocks locals)))
        (string-append "({"
                       in-block ":"
                       (parse-block ncontext (cdddr sexp))
                       out-block ":" ";"
                       "})")))
     ((eq? opcode 'br_table)
      (let* ((labels (filter (lambda (b) (not (list? b))) (cdr sexp)))
             (exps (filter (lambda (b) (list? b)) (cdr sexp)))
             (n (length labels))
             ;;(lblocks (map (lambda (b) (cons b (gen-block))) labels))
             (lblocks (map (lambda (b) (cdr (assoc b blocks))) labels))
             (nblocks (append lblocks blocks))
             (cases (map (lambda (i)
                           (if (= i (- n 1))
                               "default:"
                               (string-append "case " (number->string i) ":")))
                         (for/list ([k (in-range n)]) k)))
             (stmts (map (lambda (l)
                           (string-append "goto " l ";"))
                         lblocks))
             (lall (for/list ([c cases]
                              [s stmts])
                             (string-append c "\n\t" s "\n")))
             (out (apply string-append lall)))
        (string-append "switch ("
                       (parse context (car exps))
                       ") {\n"
                       out
                       "}")))
     )))

(write (parse '(() ()) '(block $b1 (br_table $b1 $b1 (i32.const 0)))))

