--- src/evdev.c.orig	2015-01-13 14:06:29.000000000 +0100
+++ src/evdev.c	2015-01-13 14:11:54.000000000 +0100
@@ -39,7 +39,9 @@
 
 #include <linux/version.h>
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
@@ -1078,11 +1084,13 @@
     do {
         rc = libevdev_next_event(pEvdev->dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
         if (rc < 0) {
-            if (rc == -ENODEV) /* May happen after resume */
+            if (rc != -EAGAIN && rc != -EINTR && rc != -EWOULDBLOCK) {
+                /* May happen after resume or at device detach */
                 xf86RemoveEnabledDevice(pInfo);
-            else if (rc != -EAGAIN)
+                EvdevCloseDevice(pInfo);
                 LogMessageVerbSigSafe(X_ERROR, 0, "%s: Read error: %s\n", pInfo->name,
                                        strerror(-rc));
+            }
             break;
         } else if (rc == LIBEVDEV_READ_STATUS_SUCCESS) {
 #ifdef MULTITOUCH
@@ -1436,10 +1444,15 @@
             continue;
 
         abs = libevdev_get_abs_info(pEvdev->dev, axis);
+#if defined(__linux__)
 #if LINUX_VERSION_CODE > KERNEL_VERSION(2, 6, 30)
         /* Kernel provides units/mm, X wants units/m */
         resolution = abs->resolution * 1000;
 #endif
+#else
+        /* Kernel provides units/mm, X wants units/m */
+        resolution = abs->resolution * 1000;
+#endif
 
         xf86InitValuatorAxisStruct(device, axnum,
                                    atoms[axnum],
