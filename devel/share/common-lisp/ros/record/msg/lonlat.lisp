; Auto-generated. Do not edit!


(cl:in-package record-msg)


;//! \htmlinclude lonlat.msg.html

(cl:defclass <lonlat> (roslisp-msg-protocol:ros-message)
  ((lon
    :reader lon
    :initarg :lon
    :type cl:float
    :initform 0.0)
   (lat
    :reader lat
    :initarg :lat
    :type cl:float
    :initform 0.0))
)

(cl:defclass lonlat (<lonlat>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <lonlat>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'lonlat)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name record-msg:<lonlat> is deprecated: use record-msg:lonlat instead.")))

(cl:ensure-generic-function 'lon-val :lambda-list '(m))
(cl:defmethod lon-val ((m <lonlat>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader record-msg:lon-val is deprecated.  Use record-msg:lon instead.")
  (lon m))

(cl:ensure-generic-function 'lat-val :lambda-list '(m))
(cl:defmethod lat-val ((m <lonlat>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader record-msg:lat-val is deprecated.  Use record-msg:lat instead.")
  (lat m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <lonlat>) ostream)
  "Serializes a message object of type '<lonlat>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'lon))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'lat))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <lonlat>) istream)
  "Deserializes a message object of type '<lonlat>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lon) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lat) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<lonlat>)))
  "Returns string type for a message object of type '<lonlat>"
  "record/lonlat")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'lonlat)))
  "Returns string type for a message object of type 'lonlat"
  "record/lonlat")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<lonlat>)))
  "Returns md5sum for a message object of type '<lonlat>"
  "efe88e83fa64b7150dd2703ea6640d94")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'lonlat)))
  "Returns md5sum for a message object of type 'lonlat"
  "efe88e83fa64b7150dd2703ea6640d94")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<lonlat>)))
  "Returns full string definition for message of type '<lonlat>"
  (cl:format cl:nil "float32  lon~%float32  lat~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'lonlat)))
  "Returns full string definition for message of type 'lonlat"
  (cl:format cl:nil "float32  lon~%float32  lat~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <lonlat>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <lonlat>))
  "Converts a ROS message object to a list"
  (cl:list 'lonlat
    (cl:cons ':lon (lon msg))
    (cl:cons ':lat (lat msg))
))
