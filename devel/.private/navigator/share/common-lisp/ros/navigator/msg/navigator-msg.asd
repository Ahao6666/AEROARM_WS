
(cl:in-package :asdf)

(defsystem "navigator-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "action" :depends-on ("_package_action"))
    (:file "_package_action" :depends-on ("_package"))
    (:file "interface" :depends-on ("_package_interface"))
    (:file "_package_interface" :depends-on ("_package"))
    (:file "response" :depends-on ("_package_response"))
    (:file "_package_response" :depends-on ("_package"))
  ))