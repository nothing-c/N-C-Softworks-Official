;;      ###         ###       #########  ###########     ##########   #########  #############
;;     ######      ###       ###        ###             ###    ###   ###             ###
;;    ###  ###    ###       ###          ##########    ###    ###   ########        ###
;;   ###    ###  ###  ###  ###                   ###  ###    ###   ###             ###
;;  ###      ######       ###                   ###  ###    ###   ###             ###
;; ###        ###        ###########  ###########   ##########   ###             ###

;; N-C Quick Calendar v1.0
;; Usage: M-x make-calendar

;; Inspired by this guy: https://davidseah.com/node/compact-calendar/
;; Great visualization, love it, but Excel reliance isn't great
;; (especially for date and time)
;; Instead, here's a purely numerical version using some algorithms from old
;; priests and our boy Carl Friedrich Gauss

;; Dumps to a temp buffer for convenience. If you'd like to have a paper copy,
;; just save it to a textfile and print!

;;general use for month gen
(defun iotah (x) (if (eq x 0) '() (cons x (iotah (- x 1)))))
(defun iota (x) (reverse (iotah x)))

(defun leapp (x) (or (and (= 0 (% x 4)) (not (= 0 (% x 100)))) (and (= 0 (% x 100)) (= 0 (% x 400))))) ;;are we in a leap year?
(defun start (x) (% (+ 1 (* 5 (% (- x 1) 4)) (* 4 (% (- x 1) 100)) (* 6 (% (- x 1) 400))) 7)) ;;day of week start (nicked from Gauss); 0 = sunday, 1 = monday, etc
(defun spad (x) (if (> 0 (- x 1)) 6 (- x 1))) ;;start of year pad #
(defun epad (x) (- 6 (spad x))) ;;eoy pad #
(defun gpf (x) (if (eq x 0) '() (cons (- 32 x) (gpf (- x 1))))) ;;gen pad forward

;;return formatted list of dates by row
(defun dump (x) (if (eq x '()) '() (cons (format "%02d %02d %02d %02d %02d %02d %02d" (nth 0 x) (nth 1 x) (nth 2 x) (nth 3 x) (nth 4 x) (nth 5 x) (nth 6 x)) (dump (nthcdr 7 x)))))

;; add months; check for a month start and add a month specifier if so
;; monthlist dayrows
(defun am (x y) (cond ((eq y '()) '()) ((eq x '()) y) ((not (eq '() (string-match "01" (car y)))) (cons (concat (car y) " " (car x)) (am (cdr x) (cdr y)))) (t (cons (car y) (am x (cdr y))))))

(defun make-calendar ()
  "Make a quick, text-based candybar calendar"
  (interactive)
  (let* ((y (read (read-string "Year: "))) (l (leapp y)) (s (start y))
	(o (nconc
	    (gpf (spad s))
	    (iota 31)
	    (if l (iota 29) (iota 28))
	    (iota 31)
	    (iota 30)
	    (iota 31)
	    (iota 30)
	    (iota 31)
	    (iota 31)
	    (iota 30)
	    (iota 31)
	    (iota 30)
	    (iota 31)
	    (iota (epad (if l (+ s 1) s)))))) ;;account for leap day
    (with-output-to-temp-buffer "*make-calendar*"
      (princ (format "%d\nMo Tu We Th Fr Sa Su\n" y))
      (mapcar '(lambda (x) (princ (concat x "\n"))) (am '("Jan" "Feb" "Mar" "Apr" "May" "Jun" "Jul" "Aug" "Sep" "Oct" "Nov" "Dec") (dump o))))))
