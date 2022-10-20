
(cl:in-package :asdf)

(defsystem "task_plan-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "traj_out_msg" :depends-on ("_package_traj_out_msg"))
    (:file "_package_traj_out_msg" :depends-on ("_package"))
    (:file "traj_solver_msg" :depends-on ("_package_traj_solver_msg"))
    (:file "_package_traj_solver_msg" :depends-on ("_package"))
  ))