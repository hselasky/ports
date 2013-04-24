--- ./plugins/input_uvc/uvcvideo.h.orig	2013-04-24 07:13:49.000000000 +0000
+++ ./plugins/input_uvc/uvcvideo.h	2013-04-24 07:15:33.000000000 +0000
@@ -25,12 +25,8 @@
 #ifndef _USB_VIDEO_H_
 #define _USB_VIDEO_H_
 
-#include <linux/kernel.h>
 #include <linux/videodev.h>
 
-/* Compatibility */
-#include "uvc_compat.h"
-
 /*
  * Private V4L2 control identifiers.
  */
@@ -107,7 +103,7 @@
 	__u8 unit;
 	__u8 selector;
 	__u16 size;
-	__u8 __user *data;
+	__u8 *data;
 };
 
 #define UVCIOC_CTRL_ADD		_IOW  ('U', 1, struct uvc_xu_control_info)
