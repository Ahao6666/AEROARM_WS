; Auto-generated. Do not edit!


(cl:in-package clik-srv)


;//! \htmlinclude traj_out_msg-request.msg.html

(cl:defclass <traj_out_msg-request> (roslisp-msg-protocol:ros-message)
  ((times
    :reader times
    :initarg :times
    :type cl:real
    :initform 0))
)

(cl:defclass traj_out_msg-request (<traj_out_msg-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <traj_out_msg-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'traj_out_msg-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name clik-srv:<traj_out_msg-request> is deprecated: use clik-srv:traj_out_msg-request instead.")))

(cl:ensure-generic-function 'times-val :lambda-list '(m))
(cl:defmethod times-val ((m <traj_out_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-srv:times-val is deprecated.  Use clik-srv:times instead.")
  (times m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <traj_out_msg-request>) ostream)
  "Serializes a message object of type '<traj_out_msg-request>"
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'times)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'times) (cl:floor (cl:slot-value msg 'times)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <traj_out_msg-request>) istream)
  "Deserializes a message object of type '<traj_out_msg-request>"
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'times) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<traj_out_msg-request>)))
  "Returns string type for a service object of type '<traj_out_msg-request>"
  "clik/traj_out_msgRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'traj_out_msg-request)))
  "Returns string type for a service object of type 'traj_out_msg-request"
  "clik/traj_out_msgRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<traj_out_msg-request>)))
  "Returns md5sum for a message object of type '<traj_out_msg-request>"
  "d5e5f46daf7567dab08610da48ae237e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'traj_out_msg-request)))
  "Returns md5sum for a message object of type 'traj_out_msg-request"
  "d5e5f46daf7567dab08610da48ae237e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<traj_out_msg-request>)))
  "Returns full string definition for message of type '<traj_out_msg-request>"
  (cl:format cl:nil "time times~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'traj_out_msg-request)))
  "Returns full string definition for message of type 'traj_out_msg-request"
  (cl:format cl:nil "time times~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <traj_out_msg-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <traj_out_msg-request>))
  "Converts a ROS message object to a list"
  (cl:list 'traj_out_msg-request
    (cl:cons ':times (times msg))
))
;//! \htmlinclude traj_out_msg-response.msg.html

(cl:defclass <traj_out_msg-response> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (dx
    :reader dx
    :initarg :dx
    :type cl:float
    :initform 0.0)
   (ddx
    :reader ddx
    :initarg :ddx
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0)
   (dy
    :reader dy
    :initarg :dy
    :type cl:float
    :initform 0.0)
   (ddy
    :reader ddy
    :initarg :ddy
    :type cl:float
    :initform 0.0)
   (z
    :reader z
    :initarg :z
    :type cl:float
    :initform 0.0)
   (dz
    :reader dz
    :initarg :dz
    :type cl:float
    :initform 0.0)
   (ddz
    :reader ddz
    :initarg :ddz
    :type cl:float
    :initform 0.0)
   (flag_begin
    :reader flag_begin
    :initarg :flag_begin
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass traj_out_msg-response (<traj_out_msg-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <traj_out_msg-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'traj_out_msg-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name clik-srv:<traj_out_msg-response> is deprecated: use clik-srv:traj_out_msg-response instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <traj_out_msg-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-srv:x-val is deprecated.  Use clik-srv:x instead.")
  (x m))

(cl:ensure-generic-function 'dx-val :lambda-list '(m))
(cl:defmethod dx-val ((m <traj_out_msg-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-srv:dx-val is deprecated.  Use clik-srv:dx instead.")
  (dx m))

(cl:ensure-generic-function 'ddx-val :lambda-list '(m))
(cl:defmethod ddx-val ((m <traj_out_msg-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-srv:ddx-val is deprecated.  Use clik-srv:ddx instead.")
  (ddx m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <traj_out_msg-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-srv:y-val is deprecated.  Use clik-srv:y instead.")
  (y m))

(cl:ensure-generic-function 'dy-val :lambda-list '(m))
(cl:defmethod dy-val ((m <traj_out_msg-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-srv:dy-val is deprecated.  Use clik-srv:dy instead.")
  (dy m))

(cl:ensure-generic-function 'ddy-val :lambda-list '(m))
(cl:defmethod ddy-val ((m <traj_out_msg-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-srv:ddy-val is deprecated.  Use clik-srv:ddy instead.")
  (ddy m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <traj_out_msg-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-srv:z-val is deprecated.  Use clik-srv:z instead.")
  (z m))

(cl:ensure-generic-function 'dz-val :lambda-list '(m))
(cl:defmethod dz-val ((m <traj_out_msg-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-srv:dz-val is deprecated.  Use clik-srv:dz instead.")
  (dz m))

(cl:ensure-generic-function 'ddz-val :lambda-list '(m))
(cl:defmethod ddz-val ((m <traj_out_msg-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-srv:ddz-val is deprecated.  Use clik-srv:ddz instead.")
  (ddz m))

(cl:ensure-generic-function 'flag_begin-val :lambda-list '(m))
(cl:defmethod flag_begin-val ((m <traj_out_msg-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader clik-srv:flag_begin-val is deprecated.  Use clik-srv:flag_begin instead.")
  (flag_begin m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <traj_out_msg-response>) ostream)
  "Serializes a message object of type '<traj_out_msg-response>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'dx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ddx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'dy))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ddy))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'dz))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ddz))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'flag_begin) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <traj_out_msg-response>) istream)
  "Deserializes a message object of type '<traj_out_msg-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dx) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ddx) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dy) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ddy) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dz) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ddz) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:slot-value msg 'flag_begin) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<traj_out_msg-response>)))
  "Returns string type for a service object of type '<traj_out_msg-response>"
  "clik/traj_out_msgResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'traj_out_msg-response)))
  "Returns string type for a service object of type 'traj_out_msg-response"
  "clik/traj_out_msgResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<traj_out_msg-response>)))
  "Returns md5sum for a message object of type '<traj_out_msg-response>"
  "d5e5f46daf7567dab08610da48ae237e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'traj_out_msg-response)))
  "Returns md5sum for a message object of type 'traj_out_msg-response"
  "d5e5f46daf7567dab08610da48ae237e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<traj_out_msg-response>)))
  "Returns full string definition for message of type '<traj_out_msg-response>"
  (cl:format cl:nil "float64 x~%float64 dx~%float64 ddx~%float64 y~%float64 dy~%float64 ddy~%float64 z~%float64 dz~%float64 ddz~%bool flag_begin~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'traj_out_msg-response)))
  "Returns full string definition for message of type 'traj_out_msg-response"
  (cl:format cl:nil "float64 x~%float64 dx~%float64 ddx~%float64 y~%float64 dy~%float64 ddy~%float64 z~%float64 dz~%float64 ddz~%bool flag_begin~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <traj_out_msg-response>))
  (cl:+ 0
     8
     8
     8
     8
     8
     8
     8
     8
     8
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <traj_out_msg-response>))
  "Converts a ROS message object to a list"
  (cl:list 'traj_out_msg-response
    (cl:cons ':x (x msg))
    (cl:cons ':dx (dx msg))
    (cl:cons ':ddx (ddx msg))
    (cl:cons ':y (y msg))
    (cl:cons ':dy (dy msg))
    (cl:cons ':ddy (ddy msg))
    (cl:cons ':z (z msg))
    (cl:cons ':dz (dz msg))
    (cl:cons ':ddz (ddz msg))
    (cl:cons ':flag_begin (flag_begin msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'traj_out_msg)))
  'traj_out_msg-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'traj_out_msg)))
  'traj_out_msg-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'traj_out_msg)))
  "Returns string type for a service object of type '<traj_out_msg>"
  "clik/traj_out_msg")