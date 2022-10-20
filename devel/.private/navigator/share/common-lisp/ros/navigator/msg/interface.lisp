; Auto-generated. Do not edit!


(cl:in-package navigator-msg)


;//! \htmlinclude interface.msg.html

(cl:defclass <interface> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (behavior
    :reader behavior
    :initarg :behavior
    :type cl:fixnum
    :initform 0)
   (behaviormode
    :reader behaviormode
    :initarg :behaviormode
    :type cl:fixnum
    :initform 0)
   (params
    :reader params
    :initarg :params
    :type cl:float
    :initform 0.0))
)

(cl:defclass interface (<interface>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <interface>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'interface)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name navigator-msg:<interface> is deprecated: use navigator-msg:interface instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <interface>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader navigator-msg:header-val is deprecated.  Use navigator-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'behavior-val :lambda-list '(m))
(cl:defmethod behavior-val ((m <interface>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader navigator-msg:behavior-val is deprecated.  Use navigator-msg:behavior instead.")
  (behavior m))

(cl:ensure-generic-function 'behaviormode-val :lambda-list '(m))
(cl:defmethod behaviormode-val ((m <interface>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader navigator-msg:behaviormode-val is deprecated.  Use navigator-msg:behaviormode instead.")
  (behaviormode m))

(cl:ensure-generic-function 'params-val :lambda-list '(m))
(cl:defmethod params-val ((m <interface>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader navigator-msg:params-val is deprecated.  Use navigator-msg:params instead.")
  (params m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <interface>) ostream)
  "Serializes a message object of type '<interface>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'behavior)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'behaviormode)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'params))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <interface>) istream)
  "Deserializes a message object of type '<interface>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'behavior)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'behaviormode)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'params) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<interface>)))
  "Returns string type for a message object of type '<interface>"
  "navigator/interface")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'interface)))
  "Returns string type for a message object of type 'interface"
  "navigator/interface")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<interface>)))
  "Returns md5sum for a message object of type '<interface>"
  "dae9a4e6d7acf972163a081d07c9c96d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'interface)))
  "Returns md5sum for a message object of type 'interface"
  "dae9a4e6d7acf972163a081d07c9c96d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<interface>)))
  "Returns full string definition for message of type '<interface>"
  (cl:format cl:nil "#(1) waypoint flight: x,y,z,yaw in ENU frame~%~%Header header~%uint8  behavior~%uint8  behaviormode~%float64 params~%#geometry_msgs/PoseStamped[] uav_waypoint~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'interface)))
  "Returns full string definition for message of type 'interface"
  (cl:format cl:nil "#(1) waypoint flight: x,y,z,yaw in ENU frame~%~%Header header~%uint8  behavior~%uint8  behaviormode~%float64 params~%#geometry_msgs/PoseStamped[] uav_waypoint~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <interface>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <interface>))
  "Converts a ROS message object to a list"
  (cl:list 'interface
    (cl:cons ':header (header msg))
    (cl:cons ':behavior (behavior msg))
    (cl:cons ':behaviormode (behaviormode msg))
    (cl:cons ':params (params msg))
))
