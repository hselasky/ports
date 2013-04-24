--- ./utils.c.orig	2013-04-24 07:13:49.000000000 +0000
+++ ./utils.c	2013-04-24 07:15:33.000000000 +0000
@@ -23,10 +23,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
-#include <linux/types.h>
+#include <sys/stat.h>
 #include <string.h>
 #include <fcntl.h>
-#include <wait.h>
 #include <time.h>
 #include <limits.h>
 
