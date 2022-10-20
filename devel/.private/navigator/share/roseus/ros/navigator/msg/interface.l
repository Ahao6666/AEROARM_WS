;; Auto-generated. Do not edit!


(when (boundp 'navigator::interface)
  (if (not (find-package "NAVIGATOR"))
    (make-package "NAVIGATOR"))
  (shadow 'interface (find-package "NAVIGATOR")))
(unless (find-package "NAVIGATOR::INTERFACE")
  (make-package "NAVIGATOR::INTERFACE"))

(in-package "ROS")
;;//! \htmlinclude interface.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass navigator::interface
  :super ros::object
  :slots (_header _behavior _behaviormode _params ))

(defmethod navigator::interface
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:behavior __behavior) 0)
    ((:behaviormode __behaviormode) 0)
    ((:params __params) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _behavior (round __behavior))
   (setq _behaviormode (round __behaviormode))
   (setq _params (float __params))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:behavior
   (&optional __behavior)
   (if __behavior (setq _behavior __behavior)) _behavior)
  (:behaviormode
   (&optional __behaviormode)
   (if __behaviormode (setq _behaviormode __behaviormode)) _behaviormode)
  (:params
   (&optional __params)
   (if __params (setq _params __params)) _params)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _behavior
    1
    ;; uint8 _behaviormode
    1
    ;; float64 _params
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _behavior
       (write-byte _behavior s)
     ;; uint8 _behaviormode
       (write-byte _behaviormode s)
     ;; float64 _params
       (sys::poke _params (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _behavior
     (setq _behavior (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _behaviormode
     (setq _behaviormode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _params
     (setq _params (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get navigator::interface :md5sum-) "dae9a4e6d7acf972163a081d07c9c96d")
(setf (get navigator::interface :datatype-) "navigator/interface")
(setf (get navigator::interface :definition-)
      "#(1) waypoint flight: x,y,z,yaw in ENU frame

Header header
uint8  behavior
uint8  behaviormode
float64 params
#geometry_msgs/PoseStamped[] uav_waypoint

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :navigator/interface "dae9a4e6d7acf972163a081d07c9c96d")


