
(cl:in-package :asdf)

(defsystem "calibration-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "action" :depends-on ("_package_action"))
    (:file "_package_action" :depends-on ("_package"))
    (:file "position_pub" :depends-on ("_package_position_pub"))
    (:file "_package_position_pub" :depends-on ("_package"))
  ))