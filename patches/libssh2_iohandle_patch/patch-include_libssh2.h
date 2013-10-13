--- include/libssh2.h.orig    2012-11-28 01:45:21.000000000 +0400
+++ include/libssh2.h 2013-10-12 20:27:11.000000000 +0400
@@ -413,6 +413,11 @@
 /* Global API */
 #define LIBSSH2_INIT_NO_CRYPTO        0x0001
 
+/* Last IO operation */
+#define LIBSSH2_LAST_IO_NONE                    0
+#define LIBSSH2_LAST_IO_SEND                    1
+#define LIBSSH2_LAST_IO_RECV                    2
+
 /*
  * libssh2_init()
  *
@@ -501,6 +506,7 @@
                                            char **errmsg,
                                            int *errmsg_len, int want_buf);
 LIBSSH2_API int libssh2_session_last_errno(LIBSSH2_SESSION *session);
+LIBSSH2_API int libssh2_session_last_io(LIBSSH2_SESSION *session);
 LIBSSH2_API int libssh2_session_block_directions(LIBSSH2_SESSION *session);
 
 LIBSSH2_API int libssh2_session_flag(LIBSSH2_SESSION *session, int flag,
