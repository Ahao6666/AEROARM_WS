
(cl:in-package :asdf)

(defsystem "sim2real-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "position_pub" :depends-on ("_package_position_pub"))
    (:file "_package_position_pub" :depends-on ("_package"))
    (:file "velocity_pub" :depends-on ("_package_velocity_pub"))
    (:file "_package_velocity_pub" :depends-on ("_package"))
  ))