;; Auto-generated. Do not edit!


(when (boundp 'calibration::manipulator_mode)
  (if (not (find-package "CALIBRATION"))
    (make-package "CALIBRATION"))
  (shadow 'manipulator_mode (find-package "CALIBRATION")))
(unless (find-package "CALIBRATION::MANIPULATOR_MODE")
  (make-package "CALIBRATION::MANIPULATOR_MODE"))
(unless (find-package "CALIBRATION::MANIPULATOR_MODEREQUEST")
  (make-package "CALIBRATION::MANIPULATOR_MODEREQUEST"))
(unless (find-package "CALIBRATION::MANIPULATOR_MODERESPONSE")
  (make-package "CALIBRATION::MANIPULATOR_MODERESPONSE"))

(in-package "ROS")





(defclass calibration::manipulator_modeRequest
  :super ros::object
  :slots (_mode ))

(defmethod calibration::manipulator_modeRequest
  (:init
   (&key
    ((:mode __mode) 0)
    )
   (send-super :init)
   (setq _mode (round __mode))
   self)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:serialization-length
   ()
   (+
    ;; int64 _mode
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _mode
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _mode (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _mode) (= (length (_mode . bv)) 2)) ;; bignum
              (write-long (ash (elt (_mode . bv) 0) 0) s)
              (write-long (ash (elt (_mode . bv) 1) -1) s))
             ((and (class _mode) (= (length (_mode . bv)) 1)) ;; big1
              (write-long (elt (_mode . bv) 0) s)
              (write-long (if (>= _mode 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _mode s)(write-long (if (>= _mode 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _mode
#+(or :alpha :irix6 :x86_64)
      (setf _mode (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _mode (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(defclass calibration::manipulator_modeResponse
  :super ros::object
  :slots (_result ))

(defmethod calibration::manipulator_modeResponse
  (:init
   (&key
    ((:result __result) nil)
    )
   (send-super :init)
   (setq _result __result)
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; bool _result
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _result
       (if _result (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _result
     (setq _result (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass calibration::manipulator_mode
  :super ros::object
  :slots ())

(setf (get calibration::manipulator_mode :md5sum-) "824ed9c4ea0b3e2aae8eb76e8fc86e2c")
(setf (get calibration::manipulator_mode :datatype-) "calibration/manipulator_mode")
(setf (get calibration::manipulator_mode :request) calibration::manipulator_modeRequest)
(setf (get calibration::manipulator_mode :response) calibration::manipulator_modeResponse)

(defmethod calibration::manipulator_modeRequest
  (:response () (instance calibration::manipulator_modeResponse :init)))

(setf (get calibration::manipulator_modeRequest :md5sum-) "824ed9c4ea0b3e2aae8eb76e8fc86e2c")
(setf (get calibration::manipulator_modeRequest :datatype-) "calibration/manipulator_modeRequest")
(setf (get calibration::manipulator_modeRequest :definition-)
      "int64 mode
---
bool result
")

(setf (get calibration::manipulator_modeResponse :md5sum-) "824ed9c4ea0b3e2aae8eb76e8fc86e2c")
(setf (get calibration::manipulator_modeResponse :datatype-) "calibration/manipulator_modeResponse")
(setf (get calibration::manipulator_modeResponse :definition-)
      "int64 mode
---
bool result
")



(provide :calibration/manipulator_mode "824ed9c4ea0b3e2aae8eb76e8fc86e2c")


