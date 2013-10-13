--- src/session.c.orig        2012-07-25 03:03:27.000000000 +0400
+++ ./src/session.c     2013-10-12 20:27:11.000000000 +0400
@@ -117,6 +117,7 @@
 
         ret = LIBSSH2_RECV(session, &c, 1,
                             LIBSSH2_SOCKET_RECV_FLAGS(session));
+       session->lastIO_state = LIBSSH2_LAST_IO_RECV;               
         if (ret < 0) {
             if(session->api_block_mode || (ret != -EAGAIN))
                 /* ignore EAGAIN when non-blocking */
@@ -1267,6 +1268,17 @@
     return session->err_code;
 }
 
+/* {{{ libssh2_session_last_io
+* Returns last IO operation
+*/
+LIBSSH2_API int
+libssh2_session_last_io(LIBSSH2_SESSION * session)
+{
+    return session->lastIO_state;
+}
+
+/* }}} */
+
 /* libssh2_session_flag
  *
  * Set/Get session flags
