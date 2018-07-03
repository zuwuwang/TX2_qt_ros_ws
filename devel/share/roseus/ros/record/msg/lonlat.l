;; Auto-generated. Do not edit!


(when (boundp 'record::lonlat)
  (if (not (find-package "RECORD"))
    (make-package "RECORD"))
  (shadow 'lonlat (find-package "RECORD")))
(unless (find-package "RECORD::LONLAT")
  (make-package "RECORD::LONLAT"))

(in-package "ROS")
;;//! \htmlinclude lonlat.msg.html


(defclass record::lonlat
  :super ros::object
  :slots (_lon _lat ))

(defmethod record::lonlat
  (:init
   (&key
    ((:lon __lon) 0.0)
    ((:lat __lat) 0.0)
    )
   (send-super :init)
   (setq _lon (float __lon))
   (setq _lat (float __lat))
   self)
  (:lon
   (&optional __lon)
   (if __lon (setq _lon __lon)) _lon)
  (:lat
   (&optional __lat)
   (if __lat (setq _lat __lat)) _lat)
  (:serialization-length
   ()
   (+
    ;; float32 _lon
    4
    ;; float32 _lat
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _lon
       (sys::poke _lon (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _lat
       (sys::poke _lat (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _lon
     (setq _lon (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _lat
     (setq _lat (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get record::lonlat :md5sum-) "efe88e83fa64b7150dd2703ea6640d94")
(setf (get record::lonlat :datatype-) "record/lonlat")
(setf (get record::lonlat :definition-)
      "float32  lon
float32  lat

")



(provide :record/lonlat "efe88e83fa64b7150dd2703ea6640d94")


