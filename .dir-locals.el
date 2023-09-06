((nil .
      (
       (eval . (setq flycheck-clang-include-path
                     (let ((project-root (vc-find-root "./" ".git")))
                       (list (expand-file-name "./include/" project-root)
                           (expand-file-name "./build/_deps/catch2-src/src/" project-root)))))
       (eval . (setq flycheck-gcc-include-path flycheck-clang-include-path))
       (eval . (setq flycheck-cppcheck-include-path flycheck-clang-include-path)))))


