
(cl:in-package :asdf)

(defsystem "clik-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "manipulator_mode" :depends-on ("_package_manipulator_mode"))
    (:file "_package_manipulator_mode" :depends-on ("_package"))
    (:file "traj_out_msg" :depends-on ("_package_traj_out_msg"))
    (:file "_package_traj_out_msg" :depends-on ("_package"))
    (:file "traj_solver_msg" :depends-on ("_package_traj_solver_msg"))
    (:file "_package_traj_solver_msg" :depends-on ("_package"))
  ))