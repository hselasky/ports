--- ./plugins/output_http/httpd.c.orig	2013-04-24 07:13:49.000000000 +0000
+++ ./plugins/output_http/httpd.c	2013-04-24 07:15:33.000000000 +0000
@@ -32,6 +32,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <syslog.h>
+#include <netinet/in.h>
 
 #include "../../mjpg_streamer.h"
 #include "../../utils.h"
