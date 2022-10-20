; Auto-generated. Do not edit!


(cl:in-package task_plan-srv)


;//! \htmlinclude traj_solver_msg-request.msg.html

(cl:defclass <traj_solver_msg-request> (roslisp-msg-protocol:ros-message)
  ((s_scale
    :reader s_scale
    :initarg :s_scale
    :type cl:float
    :initform 0.0)
   (x_upperPosition
    :reader x_upperPosition
    :initarg :x_upperPosition
    :type cl:float
    :initform 0.0)
   (x_lowerPosition
    :reader x_lowerPosition
    :initarg :x_lowerPosition
    :type cl:float
    :initform 0.0)
   (x_upperVelocity
    :reader x_upperVelocity
    :initarg :x_upperVelocity
    :type cl:float
    :initform 0.0)
   (x_lowerVelocity
    :reader x_lowerVelocity
    :initarg :x_lowerVelocity
    :type cl:float
    :initform 0.0)
   (x_upperAccelera
    :reader x_upperAccelera
    :initarg :x_upperAccelera
    :type cl:float
    :initform 0.0)
   (x_lowerAccelera
    :reader x_lowerAccelera
    :initarg :x_lowerAccelera
    :type cl:float
    :initform 0.0)
   (x_0
    :reader x_0
    :initarg :x_0
    :type cl:float
    :initform 0.0)
   (x_n
    :reader x_n
    :initarg :x_n
    :type cl:float
    :initform 0.0)
   (x_v0
    :reader x_v0
    :initarg :x_v0
    :type cl:float
    :initform 0.0)
   (x_vn
    :reader x_vn
    :initarg :x_vn
    :type cl:float
    :initform 0.0)
   (y_upperPosition
    :reader y_upperPosition
    :initarg :y_upperPosition
    :type cl:float
    :initform 0.0)
   (y_lowerPosition
    :reader y_lowerPosition
    :initarg :y_lowerPosition
    :type cl:float
    :initform 0.0)
   (y_upperVelocity
    :reader y_upperVelocity
    :initarg :y_upperVelocity
    :type cl:float
    :initform 0.0)
   (y_lowerVelocity
    :reader y_lowerVelocity
    :initarg :y_lowerVelocity
    :type cl:float
    :initform 0.0)
   (y_upperAccelera
    :reader y_upperAccelera
    :initarg :y_upperAccelera
    :type cl:float
    :initform 0.0)
   (y_lowerAccelera
    :reader y_lowerAccelera
    :initarg :y_lowerAccelera
    :type cl:float
    :initform 0.0)
   (y_0
    :reader y_0
    :initarg :y_0
    :type cl:float
    :initform 0.0)
   (y_n
    :reader y_n
    :initarg :y_n
    :type cl:float
    :initform 0.0)
   (y_v0
    :reader y_v0
    :initarg :y_v0
    :type cl:float
    :initform 0.0)
   (y_vn
    :reader y_vn
    :initarg :y_vn
    :type cl:float
    :initform 0.0)
   (z_upperPosition
    :reader z_upperPosition
    :initarg :z_upperPosition
    :type cl:float
    :initform 0.0)
   (z_lowerPosition
    :reader z_lowerPosition
    :initarg :z_lowerPosition
    :type cl:float
    :initform 0.0)
   (z_upperVelocity
    :reader z_upperVelocity
    :initarg :z_upperVelocity
    :type cl:float
    :initform 0.0)
   (z_lowerVelocity
    :reader z_lowerVelocity
    :initarg :z_lowerVelocity
    :type cl:float
    :initform 0.0)
   (z_upperAccelera
    :reader z_upperAccelera
    :initarg :z_upperAccelera
    :type cl:float
    :initform 0.0)
   (z_lowerAccelera
    :reader z_lowerAccelera
    :initarg :z_lowerAccelera
    :type cl:float
    :initform 0.0)
   (z_0
    :reader z_0
    :initarg :z_0
    :type cl:float
    :initform 0.0)
   (z_n
    :reader z_n
    :initarg :z_n
    :type cl:float
    :initform 0.0)
   (z_v0
    :reader z_v0
    :initarg :z_v0
    :type cl:float
    :initform 0.0)
   (z_vn
    :reader z_vn
    :initarg :z_vn
    :type cl:float
    :initform 0.0))
)

(cl:defclass traj_solver_msg-request (<traj_solver_msg-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <traj_solver_msg-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'traj_solver_msg-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name task_plan-srv:<traj_solver_msg-request> is deprecated: use task_plan-srv:traj_solver_msg-request instead.")))

(cl:ensure-generic-function 's_scale-val :lambda-list '(m))
(cl:defmethod s_scale-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:s_scale-val is deprecated.  Use task_plan-srv:s_scale instead.")
  (s_scale m))

(cl:ensure-generic-function 'x_upperPosition-val :lambda-list '(m))
(cl:defmethod x_upperPosition-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:x_upperPosition-val is deprecated.  Use task_plan-srv:x_upperPosition instead.")
  (x_upperPosition m))

(cl:ensure-generic-function 'x_lowerPosition-val :lambda-list '(m))
(cl:defmethod x_lowerPosition-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:x_lowerPosition-val is deprecated.  Use task_plan-srv:x_lowerPosition instead.")
  (x_lowerPosition m))

(cl:ensure-generic-function 'x_upperVelocity-val :lambda-list '(m))
(cl:defmethod x_upperVelocity-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:x_upperVelocity-val is deprecated.  Use task_plan-srv:x_upperVelocity instead.")
  (x_upperVelocity m))

(cl:ensure-generic-function 'x_lowerVelocity-val :lambda-list '(m))
(cl:defmethod x_lowerVelocity-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:x_lowerVelocity-val is deprecated.  Use task_plan-srv:x_lowerVelocity instead.")
  (x_lowerVelocity m))

(cl:ensure-generic-function 'x_upperAccelera-val :lambda-list '(m))
(cl:defmethod x_upperAccelera-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:x_upperAccelera-val is deprecated.  Use task_plan-srv:x_upperAccelera instead.")
  (x_upperAccelera m))

(cl:ensure-generic-function 'x_lowerAccelera-val :lambda-list '(m))
(cl:defmethod x_lowerAccelera-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:x_lowerAccelera-val is deprecated.  Use task_plan-srv:x_lowerAccelera instead.")
  (x_lowerAccelera m))

(cl:ensure-generic-function 'x_0-val :lambda-list '(m))
(cl:defmethod x_0-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:x_0-val is deprecated.  Use task_plan-srv:x_0 instead.")
  (x_0 m))

(cl:ensure-generic-function 'x_n-val :lambda-list '(m))
(cl:defmethod x_n-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:x_n-val is deprecated.  Use task_plan-srv:x_n instead.")
  (x_n m))

(cl:ensure-generic-function 'x_v0-val :lambda-list '(m))
(cl:defmethod x_v0-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:x_v0-val is deprecated.  Use task_plan-srv:x_v0 instead.")
  (x_v0 m))

(cl:ensure-generic-function 'x_vn-val :lambda-list '(m))
(cl:defmethod x_vn-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:x_vn-val is deprecated.  Use task_plan-srv:x_vn instead.")
  (x_vn m))

(cl:ensure-generic-function 'y_upperPosition-val :lambda-list '(m))
(cl:defmethod y_upperPosition-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:y_upperPosition-val is deprecated.  Use task_plan-srv:y_upperPosition instead.")
  (y_upperPosition m))

(cl:ensure-generic-function 'y_lowerPosition-val :lambda-list '(m))
(cl:defmethod y_lowerPosition-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:y_lowerPosition-val is deprecated.  Use task_plan-srv:y_lowerPosition instead.")
  (y_lowerPosition m))

(cl:ensure-generic-function 'y_upperVelocity-val :lambda-list '(m))
(cl:defmethod y_upperVelocity-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:y_upperVelocity-val is deprecated.  Use task_plan-srv:y_upperVelocity instead.")
  (y_upperVelocity m))

(cl:ensure-generic-function 'y_lowerVelocity-val :lambda-list '(m))
(cl:defmethod y_lowerVelocity-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:y_lowerVelocity-val is deprecated.  Use task_plan-srv:y_lowerVelocity instead.")
  (y_lowerVelocity m))

(cl:ensure-generic-function 'y_upperAccelera-val :lambda-list '(m))
(cl:defmethod y_upperAccelera-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:y_upperAccelera-val is deprecated.  Use task_plan-srv:y_upperAccelera instead.")
  (y_upperAccelera m))

(cl:ensure-generic-function 'y_lowerAccelera-val :lambda-list '(m))
(cl:defmethod y_lowerAccelera-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:y_lowerAccelera-val is deprecated.  Use task_plan-srv:y_lowerAccelera instead.")
  (y_lowerAccelera m))

(cl:ensure-generic-function 'y_0-val :lambda-list '(m))
(cl:defmethod y_0-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:y_0-val is deprecated.  Use task_plan-srv:y_0 instead.")
  (y_0 m))

(cl:ensure-generic-function 'y_n-val :lambda-list '(m))
(cl:defmethod y_n-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:y_n-val is deprecated.  Use task_plan-srv:y_n instead.")
  (y_n m))

(cl:ensure-generic-function 'y_v0-val :lambda-list '(m))
(cl:defmethod y_v0-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:y_v0-val is deprecated.  Use task_plan-srv:y_v0 instead.")
  (y_v0 m))

(cl:ensure-generic-function 'y_vn-val :lambda-list '(m))
(cl:defmethod y_vn-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:y_vn-val is deprecated.  Use task_plan-srv:y_vn instead.")
  (y_vn m))

(cl:ensure-generic-function 'z_upperPosition-val :lambda-list '(m))
(cl:defmethod z_upperPosition-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:z_upperPosition-val is deprecated.  Use task_plan-srv:z_upperPosition instead.")
  (z_upperPosition m))

(cl:ensure-generic-function 'z_lowerPosition-val :lambda-list '(m))
(cl:defmethod z_lowerPosition-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:z_lowerPosition-val is deprecated.  Use task_plan-srv:z_lowerPosition instead.")
  (z_lowerPosition m))

(cl:ensure-generic-function 'z_upperVelocity-val :lambda-list '(m))
(cl:defmethod z_upperVelocity-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:z_upperVelocity-val is deprecated.  Use task_plan-srv:z_upperVelocity instead.")
  (z_upperVelocity m))

(cl:ensure-generic-function 'z_lowerVelocity-val :lambda-list '(m))
(cl:defmethod z_lowerVelocity-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:z_lowerVelocity-val is deprecated.  Use task_plan-srv:z_lowerVelocity instead.")
  (z_lowerVelocity m))

(cl:ensure-generic-function 'z_upperAccelera-val :lambda-list '(m))
(cl:defmethod z_upperAccelera-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:z_upperAccelera-val is deprecated.  Use task_plan-srv:z_upperAccelera instead.")
  (z_upperAccelera m))

(cl:ensure-generic-function 'z_lowerAccelera-val :lambda-list '(m))
(cl:defmethod z_lowerAccelera-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:z_lowerAccelera-val is deprecated.  Use task_plan-srv:z_lowerAccelera instead.")
  (z_lowerAccelera m))

(cl:ensure-generic-function 'z_0-val :lambda-list '(m))
(cl:defmethod z_0-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:z_0-val is deprecated.  Use task_plan-srv:z_0 instead.")
  (z_0 m))

(cl:ensure-generic-function 'z_n-val :lambda-list '(m))
(cl:defmethod z_n-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:z_n-val is deprecated.  Use task_plan-srv:z_n instead.")
  (z_n m))

(cl:ensure-generic-function 'z_v0-val :lambda-list '(m))
(cl:defmethod z_v0-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:z_v0-val is deprecated.  Use task_plan-srv:z_v0 instead.")
  (z_v0 m))

(cl:ensure-generic-function 'z_vn-val :lambda-list '(m))
(cl:defmethod z_vn-val ((m <traj_solver_msg-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:z_vn-val is deprecated.  Use task_plan-srv:z_vn instead.")
  (z_vn m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <traj_solver_msg-request>) ostream)
  "Serializes a message object of type '<traj_solver_msg-request>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 's_scale))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x_upperPosition))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x_lowerPosition))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x_upperVelocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x_lowerVelocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x_upperAccelera))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x_lowerAccelera))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x_0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x_n))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x_v0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x_vn))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y_upperPosition))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y_lowerPosition))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y_upperVelocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y_lowerVelocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y_upperAccelera))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y_lowerAccelera))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y_0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y_n))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y_v0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y_vn))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z_upperPosition))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z_lowerPosition))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z_upperVelocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z_lowerVelocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z_upperAccelera))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z_lowerAccelera))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z_0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z_n))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z_v0))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z_vn))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <traj_solver_msg-request>) istream)
  "Deserializes a message object of type '<traj_solver_msg-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 's_scale) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x_upperPosition) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x_lowerPosition) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x_upperVelocity) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x_lowerVelocity) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x_upperAccelera) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x_lowerAccelera) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x_0) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x_n) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x_v0) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x_vn) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y_upperPosition) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y_lowerPosition) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y_upperVelocity) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y_lowerVelocity) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y_upperAccelera) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y_lowerAccelera) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y_0) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y_n) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y_v0) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y_vn) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z_upperPosition) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z_lowerPosition) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z_upperVelocity) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z_lowerVelocity) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z_upperAccelera) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z_lowerAccelera) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z_0) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z_n) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z_v0) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z_vn) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<traj_solver_msg-request>)))
  "Returns string type for a service object of type '<traj_solver_msg-request>"
  "task_plan/traj_solver_msgRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'traj_solver_msg-request)))
  "Returns string type for a service object of type 'traj_solver_msg-request"
  "task_plan/traj_solver_msgRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<traj_solver_msg-request>)))
  "Returns md5sum for a message object of type '<traj_solver_msg-request>"
  "38d31568563b236264303ee6e91f80dd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'traj_solver_msg-request)))
  "Returns md5sum for a message object of type 'traj_solver_msg-request"
  "38d31568563b236264303ee6e91f80dd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<traj_solver_msg-request>)))
  "Returns full string definition for message of type '<traj_solver_msg-request>"
  (cl:format cl:nil "float64 s_scale  ~%float64 x_upperPosition ~%float64 x_lowerPosition ~%float64 x_upperVelocity~%float64 x_lowerVelocity~%float64 x_upperAccelera~%float64 x_lowerAccelera~%float64 x_0~%float64 x_n~%float64 x_v0~%float64 x_vn~%float64 y_upperPosition ~%float64 y_lowerPosition ~%float64 y_upperVelocity~%float64 y_lowerVelocity~%float64 y_upperAccelera~%float64 y_lowerAccelera~%float64 y_0~%float64 y_n~%float64 y_v0~%float64 y_vn~%float64 z_upperPosition ~%float64 z_lowerPosition ~%float64 z_upperVelocity~%float64 z_lowerVelocity~%float64 z_upperAccelera~%float64 z_lowerAccelera~%float64 z_0~%float64 z_n~%float64 z_v0~%float64 z_vn~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'traj_solver_msg-request)))
  "Returns full string definition for message of type 'traj_solver_msg-request"
  (cl:format cl:nil "float64 s_scale  ~%float64 x_upperPosition ~%float64 x_lowerPosition ~%float64 x_upperVelocity~%float64 x_lowerVelocity~%float64 x_upperAccelera~%float64 x_lowerAccelera~%float64 x_0~%float64 x_n~%float64 x_v0~%float64 x_vn~%float64 y_upperPosition ~%float64 y_lowerPosition ~%float64 y_upperVelocity~%float64 y_lowerVelocity~%float64 y_upperAccelera~%float64 y_lowerAccelera~%float64 y_0~%float64 y_n~%float64 y_v0~%float64 y_vn~%float64 z_upperPosition ~%float64 z_lowerPosition ~%float64 z_upperVelocity~%float64 z_lowerVelocity~%float64 z_upperAccelera~%float64 z_lowerAccelera~%float64 z_0~%float64 z_n~%float64 z_v0~%float64 z_vn~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <traj_solver_msg-request>))
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
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <traj_solver_msg-request>))
  "Converts a ROS message object to a list"
  (cl:list 'traj_solver_msg-request
    (cl:cons ':s_scale (s_scale msg))
    (cl:cons ':x_upperPosition (x_upperPosition msg))
    (cl:cons ':x_lowerPosition (x_lowerPosition msg))
    (cl:cons ':x_upperVelocity (x_upperVelocity msg))
    (cl:cons ':x_lowerVelocity (x_lowerVelocity msg))
    (cl:cons ':x_upperAccelera (x_upperAccelera msg))
    (cl:cons ':x_lowerAccelera (x_lowerAccelera msg))
    (cl:cons ':x_0 (x_0 msg))
    (cl:cons ':x_n (x_n msg))
    (cl:cons ':x_v0 (x_v0 msg))
    (cl:cons ':x_vn (x_vn msg))
    (cl:cons ':y_upperPosition (y_upperPosition msg))
    (cl:cons ':y_lowerPosition (y_lowerPosition msg))
    (cl:cons ':y_upperVelocity (y_upperVelocity msg))
    (cl:cons ':y_lowerVelocity (y_lowerVelocity msg))
    (cl:cons ':y_upperAccelera (y_upperAccelera msg))
    (cl:cons ':y_lowerAccelera (y_lowerAccelera msg))
    (cl:cons ':y_0 (y_0 msg))
    (cl:cons ':y_n (y_n msg))
    (cl:cons ':y_v0 (y_v0 msg))
    (cl:cons ':y_vn (y_vn msg))
    (cl:cons ':z_upperPosition (z_upperPosition msg))
    (cl:cons ':z_lowerPosition (z_lowerPosition msg))
    (cl:cons ':z_upperVelocity (z_upperVelocity msg))
    (cl:cons ':z_lowerVelocity (z_lowerVelocity msg))
    (cl:cons ':z_upperAccelera (z_upperAccelera msg))
    (cl:cons ':z_lowerAccelera (z_lowerAccelera msg))
    (cl:cons ':z_0 (z_0 msg))
    (cl:cons ':z_n (z_n msg))
    (cl:cons ':z_v0 (z_v0 msg))
    (cl:cons ':z_vn (z_vn msg))
))
;//! \htmlinclude traj_solver_msg-response.msg.html

(cl:defclass <traj_solver_msg-response> (roslisp-msg-protocol:ros-message)
  ((resultstatus
    :reader resultstatus
    :initarg :resultstatus
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass traj_solver_msg-response (<traj_solver_msg-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <traj_solver_msg-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'traj_solver_msg-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name task_plan-srv:<traj_solver_msg-response> is deprecated: use task_plan-srv:traj_solver_msg-response instead.")))

(cl:ensure-generic-function 'resultstatus-val :lambda-list '(m))
(cl:defmethod resultstatus-val ((m <traj_solver_msg-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader task_plan-srv:resultstatus-val is deprecated.  Use task_plan-srv:resultstatus instead.")
  (resultstatus m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <traj_solver_msg-response>) ostream)
  "Serializes a message object of type '<traj_solver_msg-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'resultstatus) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <traj_solver_msg-response>) istream)
  "Deserializes a message object of type '<traj_solver_msg-response>"
    (cl:setf (cl:slot-value msg 'resultstatus) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<traj_solver_msg-response>)))
  "Returns string type for a service object of type '<traj_solver_msg-response>"
  "task_plan/traj_solver_msgResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'traj_solver_msg-response)))
  "Returns string type for a service object of type 'traj_solver_msg-response"
  "task_plan/traj_solver_msgResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<traj_solver_msg-response>)))
  "Returns md5sum for a message object of type '<traj_solver_msg-response>"
  "38d31568563b236264303ee6e91f80dd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'traj_solver_msg-response)))
  "Returns md5sum for a message object of type 'traj_solver_msg-response"
  "38d31568563b236264303ee6e91f80dd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<traj_solver_msg-response>)))
  "Returns full string definition for message of type '<traj_solver_msg-response>"
  (cl:format cl:nil "bool resultstatus~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'traj_solver_msg-response)))
  "Returns full string definition for message of type 'traj_solver_msg-response"
  (cl:format cl:nil "bool resultstatus~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <traj_solver_msg-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <traj_solver_msg-response>))
  "Converts a ROS message object to a list"
  (cl:list 'traj_solver_msg-response
    (cl:cons ':resultstatus (resultstatus msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'traj_solver_msg)))
  'traj_solver_msg-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'traj_solver_msg)))
  'traj_solver_msg-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'traj_solver_msg)))
  "Returns string type for a service object of type '<traj_solver_msg>"
  "task_plan/traj_solver_msg")