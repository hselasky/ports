--- ./plugins/output_autofocus/processJPEG_onlyCenter.c.orig	2013-04-24 07:13:49.000000000 +0000
+++ ./plugins/output_autofocus/processJPEG_onlyCenter.c	2013-04-24 07:15:33.000000000 +0000
@@ -23,7 +23,7 @@
 
 #include <stdio.h>
 #include <assert.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <math.h>
 #include <stdlib.h>
 
