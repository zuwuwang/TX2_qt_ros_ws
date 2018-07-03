
(cl:in-package :asdf)

(defsystem "record-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "lonlat" :depends-on ("_package_lonlat"))
    (:file "_package_lonlat" :depends-on ("_package"))
  ))