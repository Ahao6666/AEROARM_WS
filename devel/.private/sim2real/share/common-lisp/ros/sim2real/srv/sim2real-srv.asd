
(cl:in-package :asdf)

(defsystem "sim2real-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "cmd_mode" :depends-on ("_package_cmd_mode"))
    (:file "_package_cmd_mode" :depends-on ("_package"))
  ))