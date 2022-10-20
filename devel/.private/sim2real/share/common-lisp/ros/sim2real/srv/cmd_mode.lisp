; Auto-generated. Do not edit!


(cl:in-package sim2real-srv)


;//! \htmlinclude cmd_mode-request.msg.html

(cl:defclass <cmd_mode-request> (roslisp-msg-protocol:ros-message)
  ((mode
    :reader mode
    :initarg :mode
    :type cl:integer
    :initform 0))
)

(cl:defclass cmd_mode-request (<cmd_mode-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <cmd_mode-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'cmd_mode-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sim2real-srv:<cmd_mode-request> is deprecated: use sim2real-srv:cmd_mode-request instead.")))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <cmd_mode-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sim2real-srv:mode-val is deprecated.  Use sim2real-srv:mode instead.")
  (mode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <cmd_mode-request>) ostream)
  "Serializes a message object of type '<cmd_mode-request>"
  (cl:let* ((signed (cl:slot-value msg 'mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <cmd_mode-request>) istream)
  "Deserializes a message object of type '<cmd_mode-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mode) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<cmd_mode-request>)))
  "Returns string type for a service object of type '<cmd_mode-request>"
  "sim2real/cmd_modeRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cmd_mode-request)))
  "Returns string type for a service object of type 'cmd_mode-request"
  "sim2real/cmd_modeRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<cmd_mode-request>)))
  "Returns md5sum for a message object of type '<cmd_mode-request>"
  "824ed9c4ea0b3e2aae8eb76e8fc86e2c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'cmd_mode-request)))
  "Returns md5sum for a message object of type 'cmd_mode-request"
  "824ed9c4ea0b3e2aae8eb76e8fc86e2c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<cmd_mode-request>)))
  "Returns full string definition for message of type '<cmd_mode-request>"
  (cl:format cl:nil "~%int64 mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'cmd_mode-request)))
  "Returns full string definition for message of type 'cmd_mode-request"
  (cl:format cl:nil "~%int64 mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <cmd_mode-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <cmd_mode-request>))
  "Converts a ROS message object to a list"
  (cl:list 'cmd_mode-request
    (cl:cons ':mode (mode msg))
))
;//! \htmlinclude cmd_mode-response.msg.html

(cl:defclass <cmd_mode-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass cmd_mode-response (<cmd_mode-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <cmd_mode-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'cmd_mode-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sim2real-srv:<cmd_mode-response> is deprecated: use sim2real-srv:cmd_mode-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <cmd_mode-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sim2real-srv:result-val is deprecated.  Use sim2real-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <cmd_mode-response>) ostream)
  "Serializes a message object of type '<cmd_mode-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'result) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <cmd_mode-response>) istream)
  "Deserializes a message object of type '<cmd_mode-response>"
    (cl:setf (cl:slot-value msg 'result) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<cmd_mode-response>)))
  "Returns string type for a service object of type '<cmd_mode-response>"
  "sim2real/cmd_modeResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cmd_mode-response)))
  "Returns string type for a service object of type 'cmd_mode-response"
  "sim2real/cmd_modeResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<cmd_mode-response>)))
  "Returns md5sum for a message object of type '<cmd_mode-response>"
  "824ed9c4ea0b3e2aae8eb76e8fc86e2c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'cmd_mode-response)))
  "Returns md5sum for a message object of type 'cmd_mode-response"
  "824ed9c4ea0b3e2aae8eb76e8fc86e2c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<cmd_mode-response>)))
  "Returns full string definition for message of type '<cmd_mode-response>"
  (cl:format cl:nil "bool result~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'cmd_mode-response)))
  "Returns full string definition for message of type 'cmd_mode-response"
  (cl:format cl:nil "bool result~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <cmd_mode-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <cmd_mode-response>))
  "Converts a ROS message object to a list"
  (cl:list 'cmd_mode-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'cmd_mode)))
  'cmd_mode-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'cmd_mode)))
  'cmd_mode-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'cmd_mode)))
  "Returns string type for a service object of type '<cmd_mode>"
  "sim2real/cmd_mode")