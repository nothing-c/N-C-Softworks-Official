;; go-mode.el - barebones golang mode

;; Author: nothing-c, CEO and Lord High Imperator of N-C Softworks

(setq go-font-lock-keywords
      (let* (
	    ;; define keywords regex
	    (go-keywords '("break" "case" "chan" "const" "continue" "default" "defer" "else" "fallthrough" "for" "func" "go" "goto" "if" "import" "interface" "map" "package" "range" "return" "select" "struct" "switch" "type" "var"))
	    (go-types '("bool" "string" "byte" "rune" "float32" "float64" "complex64" "complex128" "uint8" "uint16" "uint32" "uint64" "uintptr" "int8" "int16" "int32" "int64"))
	    (go-functions '("len" "cap" "close" "new" "make" "append" "copy" "delete" "complex" "real" "imag" "panic" "recover" "print" "println"))
	    ;; stuff like importing
	    (go-etc '("import" "package"))
	  
	    ;; generate regexes
	    (go-keywords-reg (regexp-opt go-keywords 'words))
	    (go-types-reg (regexp-opt go-types 'words))
	    (go-functions-reg (regexp-opt go-functions 'words))
	    (go-etc-reg (regexp-opt go-etc 'words)))

	;; set regexes
	`((,go-etc-reg . 'font-lock-preprocessor-face)
	  (,go-keywords-reg . 'font-lock-keyword-face)
	  (,go-types-reg . 'font-lock-type-face)
	  (,go-functions-reg . 'font-lock-function-name-face))))

(define-derived-mode go-mode c-mode "go"
  "Major mode for Golang work"
  (setq font-lock-defaults '((go-font-lock-keywords))))

(provide 'go-mode)
