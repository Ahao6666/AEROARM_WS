;; Auto-generated. Do not edit!


(when (boundp 'navigator::response)
  (if (not (find-package "NAVIGATOR"))
    (make-package "NAVIGATOR"))
  (shadow 'response (find-package "NAVIGATOR")))
(unless (find-package "NAVIGATOR::RESPONSE")
  (make-package "NAVIGATOR::RESPONSE"))

(in-package "ROS")
;;//! \htmlinclude response.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass navigator::response
  :super ros::object
  :slots (_header _finished_behavior _uav_id _behavior_received _behavior_finished ))

(defmethod navigator::response
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:finished_behavior __finished_behavior) 0)
    ((:uav_id __uav_id) 0)
    ((:behavior_received __behavior_received) nil)
    ((:behavior_finished __behavior_finished) nil)
    )
   (send-super :init)
   (setq _header __header)
   (setq _finished_behavior (round __finished_behavior))
   (setq _uav_id (round __uav_id))
   (setq _behavior_received __behavior_received)
   (setq _behavior_finished __behavior_finished)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:finished_behavior
   (&optional __finished_behavior)
   (if __finished_behavior (setq _finished_behavior __finished_behavior)) _finished_behavior)
  (:uav_id
   (&optional __uav_id)
   (if __uav_id (setq _uav_id __uav_id)) _uav_id)
  (:behavior_received
   (&optional __behavior_received)
   (if __behavior_received (setq _behavior_received __behavior_received)) _behavior_received)
  (:behavior_finished
   (&optional __behavior_finished)
   (if __behavior_finished (setq _behavior_finished __behavior_finished)) _behavior_finished)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int8 _finished_behavior
    1
    ;; int8 _uav_id
    1
    ;; bool _behavior_received
    1
    ;; bool _behavior_finished
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int8 _finished_behavior
       (write-byte _finished_behavior s)
     ;; int8 _uav_id
       (write-byte _uav_id s)
     ;; bool _behavior_received
       (if _behavior_received (write-byte -1 s) (write-byte 0 s))
     ;; bool _behavior_finished
       (if _behavior_finished (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int8 _finished_behavior
     (setq _finished_behavior (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _finished_behavior 127) (setq _finished_behavior (- _finished_behavior 256)))
   ;; int8 _uav_id
     (setq _uav_id (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _uav_id 127) (setq _uav_id (- _uav_id 256)))
   ;; bool _behavior_received
     (setq _behavior_received (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _behavior_finished
     (setq _behavior_finished (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get navigator::response :md5sum-) "3a2625249be6a4aa28101b91b984ef1a")
(setf (get navigator::response :datatype-) "navigator/response")
(setf (get navigator::response :definition-)
      "Header header
int8   finished_behavior
int8   uav_id
bool   behavior_received
bool   behavior_finished


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



(provide :navigator/response "3a2625249be6a4aa28101b91b984ef1a")


