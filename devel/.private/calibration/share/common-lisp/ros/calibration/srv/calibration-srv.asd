
(cl:in-package :asdf)

(defsystem "calibration-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "manipulator_mode" :depends-on ("_package_manipulator_mode"))
    (:file "_package_manipulator_mode" :depends-on ("_package"))
  ))