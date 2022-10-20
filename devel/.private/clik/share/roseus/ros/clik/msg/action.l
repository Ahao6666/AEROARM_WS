;; Auto-generated. Do not edit!


(when (boundp 'clik::action)
  (if (not (find-package "CLIK"))
    (make-package "CLIK"))
  (shadow 'action (find-package "CLIK")))
(unless (find-package "CLIK::ACTION")
  (make-package "CLIK::ACTION"))

(in-package "ROS")
;;//! \htmlinclude action.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass clik::action
  :super ros::object
  :slots (_header _uav_id _behavior _behaviormode _onlineflag _params ))

(defmethod clik::action
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:uav_id __uav_id) 0)
    ((:behavior __behavior) 0)
    ((:behaviormode __behaviormode) 0)
    ((:onlineflag __onlineflag) nil)
    ((:params __params) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _uav_id (round __uav_id))
   (setq _behavior (round __behavior))
   (setq _behaviormode (round __behaviormode))
   (setq _onlineflag __onlineflag)
   (setq _params __params)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:uav_id
   (&optional __uav_id)
   (if __uav_id (setq _uav_id __uav_id)) _uav_id)
  (:behavior
   (&optional __behavior)
   (if __behavior (setq _behavior __behavior)) _behavior)
  (:behaviormode
   (&optional __behaviormode)
   (if __behaviormode (setq _behaviormode __behaviormode)) _behaviormode)
  (:onlineflag
   (&optional __onlineflag)
   (if __onlineflag (setq _onlineflag __onlineflag)) _onlineflag)
  (:params
   (&optional __params)
   (if __params (setq _params __params)) _params)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int8 _uav_id
    1
    ;; uint8 _behavior
    1
    ;; uint8 _behaviormode
    1
    ;; bool _onlineflag
    1
    ;; float64[] _params
    (* 8    (length _params)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int8 _uav_id
       (write-byte _uav_id s)
     ;; uint8 _behavior
       (write-byte _behavior s)
     ;; uint8 _behaviormode
       (write-byte _behaviormode s)
     ;; bool _onlineflag
       (if _onlineflag (write-byte -1 s) (write-byte 0 s))
     ;; float64[] _params
     (write-long (length _params) s)
     (dotimes (i (length _params))
       (sys::poke (elt _params i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int8 _uav_id
     (setq _uav_id (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _uav_id 127) (setq _uav_id (- _uav_id 256)))
   ;; uint8 _behavior
     (setq _behavior (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _behaviormode
     (setq _behaviormode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool _onlineflag
     (setq _onlineflag (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float64[] _params
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _params (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _params i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get clik::action :md5sum-) "d74a309e044f35fbb75377947c88949e")
(setf (get clik::action :datatype-) "clik/action")
(setf (get clik::action :definition-)
      "#(1) waypoint flight: x,y,z,yaw in ENU frame

Header header
int8   uav_id
uint8  behavior
uint8  behaviormode
bool   onlineflag
float64[] params

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



(provide :clik/action "d74a309e044f35fbb75377947c88949e")


