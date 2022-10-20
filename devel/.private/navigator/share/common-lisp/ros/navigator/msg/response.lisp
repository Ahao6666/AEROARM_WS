; Auto-generated. Do not edit!


(cl:in-package navigator-msg)


;//! \htmlinclude response.msg.html

(cl:defclass <response> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (finished_behavior
    :reader finished_behavior
    :initarg :finished_behavior
    :type cl:fixnum
    :initform 0)
   (uav_id
    :reader uav_id
    :initarg :uav_id
    :type cl:fixnum
    :initform 0)
   (behavior_received
    :reader behavior_received
    :initarg :behavior_received
    :type cl:boolean
    :initform cl:nil)
   (behavior_finished
    :reader behavior_finished
    :initarg :behavior_finished
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass response (<response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name navigator-msg:<response> is deprecated: use navigator-msg:response instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader navigator-msg:header-val is deprecated.  Use navigator-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'finished_behavior-val :lambda-list '(m))
(cl:defmethod finished_behavior-val ((m <response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader navigator-msg:finished_behavior-val is deprecated.  Use navigator-msg:finished_behavior instead.")
  (finished_behavior m))

(cl:ensure-generic-function 'uav_id-val :lambda-list '(m))
(cl:defmethod uav_id-val ((m <response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader navigator-msg:uav_id-val is deprecated.  Use navigator-msg:uav_id instead.")
  (uav_id m))

(cl:ensure-generic-function 'behavior_received-val :lambda-list '(m))
(cl:defmethod behavior_received-val ((m <response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader navigator-msg:behavior_received-val is deprecated.  Use navigator-msg:behavior_received instead.")
  (behavior_received m))

(cl:ensure-generic-function 'behavior_finished-val :lambda-list '(m))
(cl:defmethod behavior_finished-val ((m <response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader navigator-msg:behavior_finished-val is deprecated.  Use navigator-msg:behavior_finished instead.")
  (behavior_finished m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <response>) ostream)
  "Serializes a message object of type '<response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'finished_behavior)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'uav_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'behavior_received) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'behavior_finished) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <response>) istream)
  "Deserializes a message object of type '<response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'finished_behavior) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'uav_id) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:setf (cl:slot-value msg 'behavior_received) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'behavior_finished) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<response>)))
  "Returns string type for a message object of type '<response>"
  "navigator/response")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'response)))
  "Returns string type for a message object of type 'response"
  "navigator/response")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<response>)))
  "Returns md5sum for a message object of type '<response>"
  "3a2625249be6a4aa28101b91b984ef1a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'response)))
  "Returns md5sum for a message object of type 'response"
  "3a2625249be6a4aa28101b91b984ef1a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<response>)))
  "Returns full string definition for message of type '<response>"
  (cl:format cl:nil "Header header~%int8   finished_behavior~%int8   uav_id~%bool   behavior_received~%bool   behavior_finished~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'response)))
  "Returns full string definition for message of type 'response"
  (cl:format cl:nil "Header header~%int8   finished_behavior~%int8   uav_id~%bool   behavior_received~%bool   behavior_finished~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <response>))
  "Converts a ROS message object to a list"
  (cl:list 'response
    (cl:cons ':header (header msg))
    (cl:cons ':finished_behavior (finished_behavior msg))
    (cl:cons ':uav_id (uav_id msg))
    (cl:cons ':behavior_received (behavior_received msg))
    (cl:cons ':behavior_finished (behavior_finished msg))
))
