;; Added by Package.el.  This must come before configurations of
;; installed packages.  Don't delete this line.  If you don't want it,
;; just comment it out by adding a semicolon to the start of the line.
;; You may delete these explanatory comments.
;; ____________________________________________________________________________
;; Aquamacs custom-file warning:
;; Warning: After loading this .emacs file, Aquamacs will also load
;; customizations from `custom-file' (customizations.el). Any settings there
;; will override those made here.
;; Consider moving your startup settings to the Preferences.el file, which
;; is loaded after `custom-file':
;; ~/Library/Preferences/Aquamacs Emacs/Preferences
;; _____________________________________________________________________________
(package-initialize)
(require 'package)
(add-to-list 'package-archives '("melpa" . "http://melpa.org/packages/"))

;; aesthetics
(scroll-bar-mode -1)
(global-linum-mode 1)
(fset 'yes-or-no-p 'y-or-n-p)
(add-to-list 'default-frame-alist '(height . 44))
(add-to-list 'default-frame-alist '(width . 147))

;; interactively do things (ido)
(ido-mode 1)
(setq ido-enable-flex-matching t)

;; ibuffer
(define-key global-map (kbd "C-x C-b") 'ibuffer)
(autoload 'ibuffer "ibuffer" "List buffers." t)
(require 'ibuf-ext)
;; (add-to-list 'ibuffer-never-show-predicates "^\\*") ;; don't show ... in buffer

;; org-mode
(require 'org)
(setq org-log-done t)
(add-to-list 'auto-mode-alist '("\\.org$" . org-mode))
(global-set-key "\C-cl" 'org-store-link)
(global-set-key "\C-ca" 'org-agenda)
(global-font-lock-mode 1)

;; AUCTeX
(setq TeX-auto-save t)
(setq TeX-parse-self t)
(setq TeX-save-query nil)
(setq TeX-PDF-mode t)
;; (seq-default TeX-master nil)
;; (setq latex-run-command "xelatex")

;; flymake
(require 'flymake)
(defun flymake-get-tex-args (file-name)
(list "pdflatex"
(list "-file-line-error" "-draftmode" "-interaction=nonstopmode" file-name)))
(add-hook 'LaTeX-mode-hook 'flymake-mode)

;; spell-checking
(setq ispell-program-name "aspell") ; could be ispell as well, depending on your preferences
(setq ispell-dictionary "english") ; this can obviously be set to any language your spell-checking program supports
(add-hook 'LaTeX-mode-hook 'flyspell-mode)
(add-hook 'LaTeX-mode-hook 'flyspell-buffer)

;; outline-mode
(defun turn-on-outline-minor-mode ()
(outline-minor-mode 1))
(add-hook 'LaTeX-mode-hook 'turn-on-outline-minor-mode)
(add-hook 'latex-mode-hook 'turn-on-outline-minor-mode)
(setq outline-minor-mode-prefix "\C-c \C-o") ; Or something else


;; keybindings
(define-key global-map (kbd "RET") 'newline-and-indent) ;; always indent with ret
(define-key global-map (kbd "M-o") 'other-window) ;; switch window
(define-key global-map (kbd "<f2>") 'eshell) ;; eshell
(setq mac-option-modifier 'meta) ;; OPTION KEY IS META KEY

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(package-selected-packages (quote (org-edna ido-vertical-mode))))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
;; ## added by OPAM user-setup for emacs / base ## 56ab50dc8996d2bb95e7856a6eddb17b ## you can edit, but keep this line
(require 'opam-user-setup "~/.emacs.d/opam-user-setup.el")
;; ## end of OPAM user-setup addition for emacs / base ## keep this line
