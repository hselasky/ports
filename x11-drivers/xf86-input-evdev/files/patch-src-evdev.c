--- src/evdev.c.orig	2014-11-26 00:33:56.000000000 +0100
+++ src/evdev.c	2015-01-12 10:31:12.000000000 +0100
@@ -37,9 +37,11 @@
 #include <X11/keysym.h>
 #include <X11/extensions/XI.h>
 
-#include <linux/version.h>
+#include <sys/param.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <libudev.h>
+#endif
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
@@ -222,6 +224,7 @@
 static BOOL
 EvdevDeviceIsVirtual(const char* devicenode)
 {
+#ifdef __linux__
     struct udev *udev = NULL;
     struct udev_device *device = NULL;
     struct stat st;
@@ -252,6 +255,9 @@
     udev_device_unref(device);
     udev_unref(udev);
     return rc;
+#else
+    return FALSE;
+#endif
 }
 
 #ifndef HAVE_SMOOTH_SCROLLING
@@ -397,7 +403,7 @@
     int i;
 
     for (i = 0; i <= 1; i++) {
-        const struct input_absinfo *abs;
+        const struct input_absinfo *abs0;
         int val;
         int calib_min;
         int calib_max;
@@ -406,7 +412,7 @@
             continue;
 
         val = valuator_mask_get(mask, i);
-        abs = libevdev_get_abs_info(pEvdev->dev, i);
+        abs0 = libevdev_get_abs_info(pEvdev->dev, i);
 
         if (i == 0) {
             calib_min = pEvdev->calibration.min_x;
@@ -417,11 +423,11 @@
         }
 
         if (pEvdev->flags & EVDEV_CALIBRATED)
-            val = xf86ScaleAxis(val, abs->maximum, abs->minimum,
+            val = xf86ScaleAxis(val, abs0->maximum, abs0->minimum,
                                 calib_max, calib_min);
 
         if ((i == 0 && pEvdev->invert_x) || (i == 1 && pEvdev->invert_y))
-            val = (abs->maximum - val + abs->minimum);
+            val = (abs0->maximum - val + abs0->minimum);
 
         valuator_mask_set(mask, i, val);
     }
@@ -1428,30 +1434,30 @@
 #endif
 
     for (axis = ABS_X; axis < ABS_MT_SLOT; axis++) {
-        const struct input_absinfo *abs;
+        const struct input_absinfo *abs0;
         int axnum = pEvdev->abs_axis_map[axis];
         int resolution = 0;
 
         if (axnum == -1)
             continue;
 
-        abs = libevdev_get_abs_info(pEvdev->dev, axis);
-#if LINUX_VERSION_CODE > KERNEL_VERSION(2, 6, 30)
+        abs0 = libevdev_get_abs_info(pEvdev->dev, axis);
+#if 1 /* LINUX_VERSION_CODE > KERNEL_VERSION(2, 6, 30) */
         /* Kernel provides units/mm, X wants units/m */
-        resolution = abs->resolution * 1000;
+        resolution = abs0->resolution * 1000;
 #endif
 
         xf86InitValuatorAxisStruct(device, axnum,
                                    atoms[axnum],
-                                   abs->minimum,
-                                   abs->maximum,
+                                   abs0->minimum,
+                                   abs0->maximum,
                                    resolution, 0, resolution, Absolute);
         xf86InitValuatorDefaults(device, axnum);
     }
 
 #ifdef MULTITOUCH
     for (axis = ABS_MT_TOUCH_MAJOR; axis <= ABS_MAX; axis++) {
-        const struct input_absinfo *abs;
+        const struct input_absinfo *abs0;
         int axnum = pEvdev->abs_axis_map[axis];
         int resolution = 0;
         int j;
@@ -1460,7 +1466,7 @@
         if (axnum < 0)
             continue;
 
-        abs = libevdev_get_abs_info(pEvdev->dev, axis);
+        abs0 = libevdev_get_abs_info(pEvdev->dev, axis);
 
         for (j = 0; j < ArrayLength(mt_axis_mappings); j++)
             if (mt_axis_mappings[j].mt_code == axis &&
@@ -1474,12 +1480,12 @@
         if (skip)
             continue;
 
-        resolution = abs->resolution * 1000;
+        resolution = abs0->resolution * 1000;
 
         xf86InitValuatorAxisStruct(device, axnum,
                                    atoms[axnum],
-                                   abs->minimum,
-                                   abs->maximum,
+                                   abs0->minimum,
+                                   abs0->maximum,
                                    resolution, 0, resolution,
                                    Absolute);
     }
@@ -2023,9 +2029,9 @@
      */
     for (i = ABS_X; i <= ABS_MAX; i++) {
         if (libevdev_has_event_code(pEvdev->dev, EV_ABS, i)) {
-            const struct input_absinfo *abs = libevdev_get_abs_info(pEvdev->dev, i);
+            const struct input_absinfo *abs0 = libevdev_get_abs_info(pEvdev->dev, i);
             xf86IDrvMsgVerb(pInfo, X_PROBED, 6, "absolute axis %#x [%d..%d]\n",
-                            i, abs->minimum, abs->maximum);
+                            i, abs0->minimum, abs0->maximum);
         }
     }
 
@@ -2077,17 +2083,17 @@
         libevdev_enable_event_code(pEvdev->dev, EV_REL, REL_Y, NULL);
     } else if (mode == Absolute)
     {
-        struct input_absinfo abs;
+        struct input_absinfo abs0;
 
-        abs.minimum = 0;
-        abs.maximum = 1000;
-        abs.value = 0;
-        abs.fuzz = 0;
-        abs.flat = 0;
-        abs.resolution = 0;
+        abs0.minimum = 0;
+        abs0.maximum = 1000;
+        abs0.value = 0;
+        abs0.fuzz = 0;
+        abs0.flat = 0;
+        abs0.resolution = 0;
 
-        libevdev_enable_event_code(pEvdev->dev, EV_ABS, ABS_X, &abs);
-        libevdev_enable_event_code(pEvdev->dev, EV_ABS, ABS_Y, &abs);
+        libevdev_enable_event_code(pEvdev->dev, EV_ABS, ABS_X, &abs0);
+        libevdev_enable_event_code(pEvdev->dev, EV_ABS, ABS_Y, &abs0);
     }
 }
 
