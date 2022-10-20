;; Auto-generated. Do not edit!


(when (boundp 'task_plan::traj_solver_msg)
  (if (not (find-package "TASK_PLAN"))
    (make-package "TASK_PLAN"))
  (shadow 'traj_solver_msg (find-package "TASK_PLAN")))
(unless (find-package "TASK_PLAN::TRAJ_SOLVER_MSG")
  (make-package "TASK_PLAN::TRAJ_SOLVER_MSG"))
(unless (find-package "TASK_PLAN::TRAJ_SOLVER_MSGREQUEST")
  (make-package "TASK_PLAN::TRAJ_SOLVER_MSGREQUEST"))
(unless (find-package "TASK_PLAN::TRAJ_SOLVER_MSGRESPONSE")
  (make-package "TASK_PLAN::TRAJ_SOLVER_MSGRESPONSE"))

(in-package "ROS")





(defclass task_plan::traj_solver_msgRequest
  :super ros::object
  :slots (_s_scale _x_upperPosition _x_lowerPosition _x_upperVelocity _x_lowerVelocity _x_upperAccelera _x_lowerAccelera _x_0 _x_n _x_v0 _x_vn _y_upperPosition _y_lowerPosition _y_upperVelocity _y_lowerVelocity _y_upperAccelera _y_lowerAccelera _y_0 _y_n _y_v0 _y_vn _z_upperPosition _z_lowerPosition _z_upperVelocity _z_lowerVelocity _z_upperAccelera _z_lowerAccelera _z_0 _z_n _z_v0 _z_vn ))

(defmethod task_plan::traj_solver_msgRequest
  (:init
   (&key
    ((:s_scale __s_scale) 0.0)
    ((:x_upperPosition __x_upperPosition) 0.0)
    ((:x_lowerPosition __x_lowerPosition) 0.0)
    ((:x_upperVelocity __x_upperVelocity) 0.0)
    ((:x_lowerVelocity __x_lowerVelocity) 0.0)
    ((:x_upperAccelera __x_upperAccelera) 0.0)
    ((:x_lowerAccelera __x_lowerAccelera) 0.0)
    ((:x_0 __x_0) 0.0)
    ((:x_n __x_n) 0.0)
    ((:x_v0 __x_v0) 0.0)
    ((:x_vn __x_vn) 0.0)
    ((:y_upperPosition __y_upperPosition) 0.0)
    ((:y_lowerPosition __y_lowerPosition) 0.0)
    ((:y_upperVelocity __y_upperVelocity) 0.0)
    ((:y_lowerVelocity __y_lowerVelocity) 0.0)
    ((:y_upperAccelera __y_upperAccelera) 0.0)
    ((:y_lowerAccelera __y_lowerAccelera) 0.0)
    ((:y_0 __y_0) 0.0)
    ((:y_n __y_n) 0.0)
    ((:y_v0 __y_v0) 0.0)
    ((:y_vn __y_vn) 0.0)
    ((:z_upperPosition __z_upperPosition) 0.0)
    ((:z_lowerPosition __z_lowerPosition) 0.0)
    ((:z_upperVelocity __z_upperVelocity) 0.0)
    ((:z_lowerVelocity __z_lowerVelocity) 0.0)
    ((:z_upperAccelera __z_upperAccelera) 0.0)
    ((:z_lowerAccelera __z_lowerAccelera) 0.0)
    ((:z_0 __z_0) 0.0)
    ((:z_n __z_n) 0.0)
    ((:z_v0 __z_v0) 0.0)
    ((:z_vn __z_vn) 0.0)
    )
   (send-super :init)
   (setq _s_scale (float __s_scale))
   (setq _x_upperPosition (float __x_upperPosition))
   (setq _x_lowerPosition (float __x_lowerPosition))
   (setq _x_upperVelocity (float __x_upperVelocity))
   (setq _x_lowerVelocity (float __x_lowerVelocity))
   (setq _x_upperAccelera (float __x_upperAccelera))
   (setq _x_lowerAccelera (float __x_lowerAccelera))
   (setq _x_0 (float __x_0))
   (setq _x_n (float __x_n))
   (setq _x_v0 (float __x_v0))
   (setq _x_vn (float __x_vn))
   (setq _y_upperPosition (float __y_upperPosition))
   (setq _y_lowerPosition (float __y_lowerPosition))
   (setq _y_upperVelocity (float __y_upperVelocity))
   (setq _y_lowerVelocity (float __y_lowerVelocity))
   (setq _y_upperAccelera (float __y_upperAccelera))
   (setq _y_lowerAccelera (float __y_lowerAccelera))
   (setq _y_0 (float __y_0))
   (setq _y_n (float __y_n))
   (setq _y_v0 (float __y_v0))
   (setq _y_vn (float __y_vn))
   (setq _z_upperPosition (float __z_upperPosition))
   (setq _z_lowerPosition (float __z_lowerPosition))
   (setq _z_upperVelocity (float __z_upperVelocity))
   (setq _z_lowerVelocity (float __z_lowerVelocity))
   (setq _z_upperAccelera (float __z_upperAccelera))
   (setq _z_lowerAccelera (float __z_lowerAccelera))
   (setq _z_0 (float __z_0))
   (setq _z_n (float __z_n))
   (setq _z_v0 (float __z_v0))
   (setq _z_vn (float __z_vn))
   self)
  (:s_scale
   (&optional __s_scale)
   (if __s_scale (setq _s_scale __s_scale)) _s_scale)
  (:x_upperPosition
   (&optional __x_upperPosition)
   (if __x_upperPosition (setq _x_upperPosition __x_upperPosition)) _x_upperPosition)
  (:x_lowerPosition
   (&optional __x_lowerPosition)
   (if __x_lowerPosition (setq _x_lowerPosition __x_lowerPosition)) _x_lowerPosition)
  (:x_upperVelocity
   (&optional __x_upperVelocity)
   (if __x_upperVelocity (setq _x_upperVelocity __x_upperVelocity)) _x_upperVelocity)
  (:x_lowerVelocity
   (&optional __x_lowerVelocity)
   (if __x_lowerVelocity (setq _x_lowerVelocity __x_lowerVelocity)) _x_lowerVelocity)
  (:x_upperAccelera
   (&optional __x_upperAccelera)
   (if __x_upperAccelera (setq _x_upperAccelera __x_upperAccelera)) _x_upperAccelera)
  (:x_lowerAccelera
   (&optional __x_lowerAccelera)
   (if __x_lowerAccelera (setq _x_lowerAccelera __x_lowerAccelera)) _x_lowerAccelera)
  (:x_0
   (&optional __x_0)
   (if __x_0 (setq _x_0 __x_0)) _x_0)
  (:x_n
   (&optional __x_n)
   (if __x_n (setq _x_n __x_n)) _x_n)
  (:x_v0
   (&optional __x_v0)
   (if __x_v0 (setq _x_v0 __x_v0)) _x_v0)
  (:x_vn
   (&optional __x_vn)
   (if __x_vn (setq _x_vn __x_vn)) _x_vn)
  (:y_upperPosition
   (&optional __y_upperPosition)
   (if __y_upperPosition (setq _y_upperPosition __y_upperPosition)) _y_upperPosition)
  (:y_lowerPosition
   (&optional __y_lowerPosition)
   (if __y_lowerPosition (setq _y_lowerPosition __y_lowerPosition)) _y_lowerPosition)
  (:y_upperVelocity
   (&optional __y_upperVelocity)
   (if __y_upperVelocity (setq _y_upperVelocity __y_upperVelocity)) _y_upperVelocity)
  (:y_lowerVelocity
   (&optional __y_lowerVelocity)
   (if __y_lowerVelocity (setq _y_lowerVelocity __y_lowerVelocity)) _y_lowerVelocity)
  (:y_upperAccelera
   (&optional __y_upperAccelera)
   (if __y_upperAccelera (setq _y_upperAccelera __y_upperAccelera)) _y_upperAccelera)
  (:y_lowerAccelera
   (&optional __y_lowerAccelera)
   (if __y_lowerAccelera (setq _y_lowerAccelera __y_lowerAccelera)) _y_lowerAccelera)
  (:y_0
   (&optional __y_0)
   (if __y_0 (setq _y_0 __y_0)) _y_0)
  (:y_n
   (&optional __y_n)
   (if __y_n (setq _y_n __y_n)) _y_n)
  (:y_v0
   (&optional __y_v0)
   (if __y_v0 (setq _y_v0 __y_v0)) _y_v0)
  (:y_vn
   (&optional __y_vn)
   (if __y_vn (setq _y_vn __y_vn)) _y_vn)
  (:z_upperPosition
   (&optional __z_upperPosition)
   (if __z_upperPosition (setq _z_upperPosition __z_upperPosition)) _z_upperPosition)
  (:z_lowerPosition
   (&optional __z_lowerPosition)
   (if __z_lowerPosition (setq _z_lowerPosition __z_lowerPosition)) _z_lowerPosition)
  (:z_upperVelocity
   (&optional __z_upperVelocity)
   (if __z_upperVelocity (setq _z_upperVelocity __z_upperVelocity)) _z_upperVelocity)
  (:z_lowerVelocity
   (&optional __z_lowerVelocity)
   (if __z_lowerVelocity (setq _z_lowerVelocity __z_lowerVelocity)) _z_lowerVelocity)
  (:z_upperAccelera
   (&optional __z_upperAccelera)
   (if __z_upperAccelera (setq _z_upperAccelera __z_upperAccelera)) _z_upperAccelera)
  (:z_lowerAccelera
   (&optional __z_lowerAccelera)
   (if __z_lowerAccelera (setq _z_lowerAccelera __z_lowerAccelera)) _z_lowerAccelera)
  (:z_0
   (&optional __z_0)
   (if __z_0 (setq _z_0 __z_0)) _z_0)
  (:z_n
   (&optional __z_n)
   (if __z_n (setq _z_n __z_n)) _z_n)
  (:z_v0
   (&optional __z_v0)
   (if __z_v0 (setq _z_v0 __z_v0)) _z_v0)
  (:z_vn
   (&optional __z_vn)
   (if __z_vn (setq _z_vn __z_vn)) _z_vn)
  (:serialization-length
   ()
   (+
    ;; float64 _s_scale
    8
    ;; float64 _x_upperPosition
    8
    ;; float64 _x_lowerPosition
    8
    ;; float64 _x_upperVelocity
    8
    ;; float64 _x_lowerVelocity
    8
    ;; float64 _x_upperAccelera
    8
    ;; float64 _x_lowerAccelera
    8
    ;; float64 _x_0
    8
    ;; float64 _x_n
    8
    ;; float64 _x_v0
    8
    ;; float64 _x_vn
    8
    ;; float64 _y_upperPosition
    8
    ;; float64 _y_lowerPosition
    8
    ;; float64 _y_upperVelocity
    8
    ;; float64 _y_lowerVelocity
    8
    ;; float64 _y_upperAccelera
    8
    ;; float64 _y_lowerAccelera
    8
    ;; float64 _y_0
    8
    ;; float64 _y_n
    8
    ;; float64 _y_v0
    8
    ;; float64 _y_vn
    8
    ;; float64 _z_upperPosition
    8
    ;; float64 _z_lowerPosition
    8
    ;; float64 _z_upperVelocity
    8
    ;; float64 _z_lowerVelocity
    8
    ;; float64 _z_upperAccelera
    8
    ;; float64 _z_lowerAccelera
    8
    ;; float64 _z_0
    8
    ;; float64 _z_n
    8
    ;; float64 _z_v0
    8
    ;; float64 _z_vn
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _s_scale
       (sys::poke _s_scale (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x_upperPosition
       (sys::poke _x_upperPosition (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x_lowerPosition
       (sys::poke _x_lowerPosition (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x_upperVelocity
       (sys::poke _x_upperVelocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x_lowerVelocity
       (sys::poke _x_lowerVelocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x_upperAccelera
       (sys::poke _x_upperAccelera (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x_lowerAccelera
       (sys::poke _x_lowerAccelera (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x_0
       (sys::poke _x_0 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x_n
       (sys::poke _x_n (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x_v0
       (sys::poke _x_v0 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _x_vn
       (sys::poke _x_vn (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y_upperPosition
       (sys::poke _y_upperPosition (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y_lowerPosition
       (sys::poke _y_lowerPosition (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y_upperVelocity
       (sys::poke _y_upperVelocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y_lowerVelocity
       (sys::poke _y_lowerVelocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y_upperAccelera
       (sys::poke _y_upperAccelera (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y_lowerAccelera
       (sys::poke _y_lowerAccelera (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y_0
       (sys::poke _y_0 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y_n
       (sys::poke _y_n (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y_v0
       (sys::poke _y_v0 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y_vn
       (sys::poke _y_vn (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z_upperPosition
       (sys::poke _z_upperPosition (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z_lowerPosition
       (sys::poke _z_lowerPosition (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z_upperVelocity
       (sys::poke _z_upperVelocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z_lowerVelocity
       (sys::poke _z_lowerVelocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z_upperAccelera
       (sys::poke _z_upperAccelera (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z_lowerAccelera
       (sys::poke _z_lowerAccelera (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z_0
       (sys::poke _z_0 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z_n
       (sys::poke _z_n (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z_v0
       (sys::poke _z_v0 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z_vn
       (sys::poke _z_vn (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _s_scale
     (setq _s_scale (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x_upperPosition
     (setq _x_upperPosition (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x_lowerPosition
     (setq _x_lowerPosition (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x_upperVelocity
     (setq _x_upperVelocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x_lowerVelocity
     (setq _x_lowerVelocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x_upperAccelera
     (setq _x_upperAccelera (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x_lowerAccelera
     (setq _x_lowerAccelera (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x_0
     (setq _x_0 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x_n
     (setq _x_n (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x_v0
     (setq _x_v0 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _x_vn
     (setq _x_vn (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y_upperPosition
     (setq _y_upperPosition (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y_lowerPosition
     (setq _y_lowerPosition (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y_upperVelocity
     (setq _y_upperVelocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y_lowerVelocity
     (setq _y_lowerVelocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y_upperAccelera
     (setq _y_upperAccelera (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y_lowerAccelera
     (setq _y_lowerAccelera (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y_0
     (setq _y_0 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y_n
     (setq _y_n (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y_v0
     (setq _y_v0 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y_vn
     (setq _y_vn (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z_upperPosition
     (setq _z_upperPosition (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z_lowerPosition
     (setq _z_lowerPosition (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z_upperVelocity
     (setq _z_upperVelocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z_lowerVelocity
     (setq _z_lowerVelocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z_upperAccelera
     (setq _z_upperAccelera (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z_lowerAccelera
     (setq _z_lowerAccelera (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z_0
     (setq _z_0 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z_n
     (setq _z_n (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z_v0
     (setq _z_v0 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z_vn
     (setq _z_vn (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass task_plan::traj_solver_msgResponse
  :super ros::object
  :slots (_resultstatus ))

(defmethod task_plan::traj_solver_msgResponse
  (:init
   (&key
    ((:resultstatus __resultstatus) nil)
    )
   (send-super :init)
   (setq _resultstatus __resultstatus)
   self)
  (:resultstatus
   (&optional __resultstatus)
   (if __resultstatus (setq _resultstatus __resultstatus)) _resultstatus)
  (:serialization-length
   ()
   (+
    ;; bool _resultstatus
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _resultstatus
       (if _resultstatus (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _resultstatus
     (setq _resultstatus (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass task_plan::traj_solver_msg
  :super ros::object
  :slots ())

(setf (get task_plan::traj_solver_msg :md5sum-) "38d31568563b236264303ee6e91f80dd")
(setf (get task_plan::traj_solver_msg :datatype-) "task_plan/traj_solver_msg")
(setf (get task_plan::traj_solver_msg :request) task_plan::traj_solver_msgRequest)
(setf (get task_plan::traj_solver_msg :response) task_plan::traj_solver_msgResponse)

(defmethod task_plan::traj_solver_msgRequest
  (:response () (instance task_plan::traj_solver_msgResponse :init)))

(setf (get task_plan::traj_solver_msgRequest :md5sum-) "38d31568563b236264303ee6e91f80dd")
(setf (get task_plan::traj_solver_msgRequest :datatype-) "task_plan/traj_solver_msgRequest")
(setf (get task_plan::traj_solver_msgRequest :definition-)
      "float64 s_scale  
float64 x_upperPosition 
float64 x_lowerPosition 
float64 x_upperVelocity
float64 x_lowerVelocity
float64 x_upperAccelera
float64 x_lowerAccelera
float64 x_0
float64 x_n
float64 x_v0
float64 x_vn
float64 y_upperPosition 
float64 y_lowerPosition 
float64 y_upperVelocity
float64 y_lowerVelocity
float64 y_upperAccelera
float64 y_lowerAccelera
float64 y_0
float64 y_n
float64 y_v0
float64 y_vn
float64 z_upperPosition 
float64 z_lowerPosition 
float64 z_upperVelocity
float64 z_lowerVelocity
float64 z_upperAccelera
float64 z_lowerAccelera
float64 z_0
float64 z_n
float64 z_v0
float64 z_vn
---
bool resultstatus

")

(setf (get task_plan::traj_solver_msgResponse :md5sum-) "38d31568563b236264303ee6e91f80dd")
(setf (get task_plan::traj_solver_msgResponse :datatype-) "task_plan/traj_solver_msgResponse")
(setf (get task_plan::traj_solver_msgResponse :definition-)
      "float64 s_scale  
float64 x_upperPosition 
float64 x_lowerPosition 
float64 x_upperVelocity
float64 x_lowerVelocity
float64 x_upperAccelera
float64 x_lowerAccelera
float64 x_0
float64 x_n
float64 x_v0
float64 x_vn
float64 y_upperPosition 
float64 y_lowerPosition 
float64 y_upperVelocity
float64 y_lowerVelocity
float64 y_upperAccelera
float64 y_lowerAccelera
float64 y_0
float64 y_n
float64 y_v0
float64 y_vn
float64 z_upperPosition 
float64 z_lowerPosition 
float64 z_upperVelocity
float64 z_lowerVelocity
float64 z_upperAccelera
float64 z_lowerAccelera
float64 z_0
float64 z_n
float64 z_v0
float64 z_vn
---
bool resultstatus

")



(provide :task_plan/traj_solver_msg "38d31568563b236264303ee6e91f80dd")


