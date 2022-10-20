; Auto-generated. Do not edit!


(cl:in-package clik-msg)


;//! \htmlinclude action.msg.html

(cl:defclass <action> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (uav_id
    :reader uav_id
    :initarg :uav_id
    :type cl:fixnum
    :initform 0)
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
   (onlineflag
    :reader onlineflag
    :initarg :onlineflag
    :type cl:boolean
    :initform cl:nil)
   (params
    :reader params
    :initarg :params
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass action (<action>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <action>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'action)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name clik-msg:<action> is deprecated: use clik-msg:action instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <action>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-msg:header-val is deprecated.  Use clik-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'uav_id-val :lambda-list '(m))
(cl:defmethod uav_id-val ((m <action>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-msg:uav_id-val is deprecated.  Use clik-msg:uav_id instead.")
  (uav_id m))

(cl:ensure-generic-function 'behavior-val :lambda-list '(m))
(cl:defmethod behavior-val ((m <action>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-msg:behavior-val is deprecated.  Use clik-msg:behavior instead.")
  (behavior m))

(cl:ensure-generic-function 'behaviormode-val :lambda-list '(m))
(cl:defmethod behaviormode-val ((m <action>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-msg:behaviormode-val is deprecated.  Use clik-msg:behaviormode instead.")
  (behaviormode m))

(cl:ensure-generic-function 'onlineflag-val :lambda-list '(m))
(cl:defmethod onlineflag-val ((m <action>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-msg:onlineflag-val is deprecated.  Use clik-msg:onlineflag instead.")
  (onlineflag m))

(cl:ensure-generic-function 'params-val :lambda-list '(m))
(cl:defmethod params-val ((m <action>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-msg:params-val is deprecated.  Use clik-msg:params instead.")
  (params m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <action>) ostream)
  "Serializes a message object of type '<action>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'uav_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'behavior)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'behaviormode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'onlineflag) 1 0)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'params))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'params))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <action>) istream)
  "Deserializes a message object of type '<action>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'uav_id) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'behavior)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'behaviormode)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'onlineflag) (cl:not (cl:zerop (cl:read-byte istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'params) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'params)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<action>)))
  "Returns string type for a message object of type '<action>"
  "clik/action")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'action)))
  "Returns string type for a message object of type 'action"
  "clik/action")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<action>)))
  "Returns md5sum for a message object of type '<action>"
  "d74a309e044f35fbb75377947c88949e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'action)))
  "Returns md5sum for a message object of type 'action"
  "d74a309e044f35fbb75377947c88949e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<action>)))
  "Returns full string definition for message of type '<action>"
  (cl:format cl:nil "#(1) waypoint flight: x,y,z,yaw in ENU frame~%~%Header header~%int8   uav_id~%uint8  behavior~%uint8  behaviormode~%bool   onlineflag~%float64[] params~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'action)))
  "Returns full string definition for message of type 'action"
  (cl:format cl:nil "#(1) waypoint flight: x,y,z,yaw in ENU frame~%~%Header header~%int8   uav_id~%uint8  behavior~%uint8  behaviormode~%bool   onlineflag~%float64[] params~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <action>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
     1
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'params) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <action>))
  "Converts a ROS message object to a list"
  (cl:list 'action
    (cl:cons ':header (header msg))
    (cl:cons ':uav_id (uav_id msg))
    (cl:cons ':behavior (behavior msg))
    (cl:cons ':behaviormode (behaviormode msg))
    (cl:cons ':onlineflag (onlineflag msg))
    (cl:cons ':params (params msg))
))
