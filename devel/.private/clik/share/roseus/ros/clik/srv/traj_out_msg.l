;; Auto-generated. Do not edit!


(when (boundp 'clik::traj_out_msg)
  (if (not (find-package "CLIK"))
    (make-package "CLIK"))
  (shadow 'traj_out_msg (find-package "CLIK")))
(unless (find-package "CLIK::TRAJ_OUT_MSG")
  (make-package "CLIK::TRAJ_OUT_MSG"))
(unless (find-package "CLIK::TRAJ_OUT_MSGREQUEST")
  (make-package "CLIK::TRAJ_OUT_MSGREQUEST"))
(unless (find-package "CLIK::TRAJ_OUT_MSGRESPONSE")
  (make-package "CLIK::TRAJ_OUT_MSGRESPONSE"))

(in-package "ROS")





(defclass clik::traj_out_msgRequest
  :super ros::object
  :slots (_times ))

(defmethod clik::traj_out_msgRequest
  (:init
   (&key
    ((:times __times) (instance ros::time :init))
    )
   (send-super :init)
   (setq _times __times)
   self)
  (:times
   (&optional __times)
   (if __times (setq _times __times)) _times)
  (:serialization-length
   ()
   (+
    ;; time _times
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; time _times
       (write-long (send _times :sec) s) (write-long (send _times :nsec) s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; time _times
     (send _times :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _times :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass clik::traj_out_msgResponse
  :super ros::object
  :slots (_x _dx _ddx _y _dy _ddy _z _dz _ddz _flag_begin ))

(defmethod clik::traj_out_msgResponse
  (:init
   (&key
    ((:x __x) 0.0)
    ((:dx __dx) 0.0)
    ((:ddx __ddx) 0.0)
    ((:y __y) 0.0)
    ((:dy __dy) 0.0)
    ((:ddy __ddy) 0.0)
    ((:z __z) 0.0)
    ((:dz __dz) 0.0)
    ((:ddz __ddz) 0.0)
    ((:flag_begin __flag_begin) nil)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _dx (float __dx))
   (setq _ddx (float __ddx))
   (setq _y (float __y))
   (setq _dy (float __dy))
   (setq _ddy (float __ddy))
   (setq _z (float __z))
   (setq _dz (float __dz))
   (setq _ddz (float __ddz))
   (setq _flag_begin __flag_begin)
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:dx
   (&optional __dx)
   (if __dx (setq _dx __dx)) _dx)
  (:ddx
   (&optional __ddx)
   (if __ddx (setq _ddx __ddx)) _ddx)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:dy
   (&optional __dy)
   (if __dy (setq _dy __dy)) _dy)
  (:ddy
   (&optional __ddy)
   (if __ddy (setq _ddy __ddy)) _ddy)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:dz
   (&optional __dz)
   (if __dz (setq _dz __dz)) _dz)
  (:ddz
   (&optional __ddz)
   (if __ddz (setq _ddz __ddz)) _ddz)
  (:flag_begin
   (&optional __flag_begin)
   (if __flag_begin (setq _flag_begin __flag_begin)) _flag_begin)
  (:serialization-length
   ()
   (+
    ;; float64 _x
    8
    ;; float64 _dx
    8
    ;; float64 _ddx
    8
    ;; float64 _y
    8
    ;; float64 _dy
    8
    ;; float64 _ddy
    8
    ;; float64 _z
    8
    ;; float64 _dz
    8
    ;; float64 _ddz
    8
    ;; bool _flag_begin
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _dx
       (sys::poke _dx (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ddx
       (sys::poke _ddx (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _dy
       (sys::poke _dy (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ddy
       (sys::poke _ddy (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z
       (sys::poke _z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _dz
       (sys::poke _dz (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ddz
       (sys::poke _ddz (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; bool _flag_begin
       (if _flag_begin (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _dx
     (setq _dx (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ddx
     (setq _ddx (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _dy
     (setq _dy (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ddy
     (setq _ddy (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z
     (setq _z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _dz
     (setq _dz (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ddz
     (setq _ddz (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; bool _flag_begin
     (setq _flag_begin (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass clik::traj_out_msg
  :super ros::object
  :slots ())

(setf (get clik::traj_out_msg :md5sum-) "d5e5f46daf7567dab08610da48ae237e")
(setf (get clik::traj_out_msg :datatype-) "clik/traj_out_msg")
(setf (get clik::traj_out_msg :request) clik::traj_out_msgRequest)
(setf (get clik::traj_out_msg :response) clik::traj_out_msgResponse)

(defmethod clik::traj_out_msgRequest
  (:response () (instance clik::traj_out_msgResponse :init)))

(setf (get clik::traj_out_msgRequest :md5sum-) "d5e5f46daf7567dab08610da48ae237e")
(setf (get clik::traj_out_msgRequest :datatype-) "clik/traj_out_msgRequest")
(setf (get clik::traj_out_msgRequest :definition-)
      "time times
---
float64 x
float64 dx
float64 ddx
float64 y
float64 dy
float64 ddy
float64 z
float64 dz
float64 ddz
bool flag_begin
")

(setf (get clik::traj_out_msgResponse :md5sum-) "d5e5f46daf7567dab08610da48ae237e")
(setf (get clik::traj_out_msgResponse :datatype-) "clik/traj_out_msgResponse")
(setf (get clik::traj_out_msgResponse :definition-)
      "time times
---
float64 x
float64 dx
float64 ddx
float64 y
float64 dy
float64 ddy
float64 z
float64 dz
float64 ddz
bool flag_begin
")



(provide :clik/traj_out_msg "d5e5f46daf7567dab08610da48ae237e")


