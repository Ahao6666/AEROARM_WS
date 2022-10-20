;; Auto-generated. Do not edit!


(when (boundp 'clik::position_pub)
  (if (not (find-package "CLIK"))
    (make-package "CLIK"))
  (shadow 'position_pub (find-package "CLIK")))
(unless (find-package "CLIK::POSITION_PUB")
  (make-package "CLIK::POSITION_PUB"))

(in-package "ROS")
;;//! \htmlinclude position_pub.msg.html


(defclass clik::position_pub
  :super ros::object
  :slots (_time_stamp _X _Y _Z ))

(defmethod clik::position_pub
  (:init
   (&key
    ((:time_stamp __time_stamp) (instance ros::time :init))
    ((:X __X) 0.0)
    ((:Y __Y) 0.0)
    ((:Z __Z) 0.0)
    )
   (send-super :init)
   (setq _time_stamp __time_stamp)
   (setq _X (float __X))
   (setq _Y (float __Y))
   (setq _Z (float __Z))
   self)
  (:time_stamp
   (&optional __time_stamp)
   (if __time_stamp (setq _time_stamp __time_stamp)) _time_stamp)
  (:X
   (&optional __X)
   (if __X (setq _X __X)) _X)
  (:Y
   (&optional __Y)
   (if __Y (setq _Y __Y)) _Y)
  (:Z
   (&optional __Z)
   (if __Z (setq _Z __Z)) _Z)
  (:serialization-length
   ()
   (+
    ;; time _time_stamp
    8
    ;; float32 _X
    4
    ;; float32 _Y
    4
    ;; float32 _Z
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; time _time_stamp
       (write-long (send _time_stamp :sec) s) (write-long (send _time_stamp :nsec) s)
     ;; float32 _X
       (sys::poke _X (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Y
       (sys::poke _Y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Z
       (sys::poke _Z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; time _time_stamp
     (send _time_stamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _time_stamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _X
     (setq _X (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Y
     (setq _Y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Z
     (setq _Z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get clik::position_pub :md5sum-) "9499d283948dec08036e4b38b8bbe0a9")
(setf (get clik::position_pub :datatype-) "clik/position_pub")
(setf (get clik::position_pub :definition-)
      "time time_stamp
float32 X
float32 Y
float32 Z


")



(provide :clik/position_pub "9499d283948dec08036e4b38b8bbe0a9")


