--- src/transport.c.orig      2012-10-08 16:54:30.000000000 +0400
+++ src/transport.c   2013-10-12 20:27:11.000000000 +0400
@@ -365,6 +365,7 @@
                 LIBSSH2_RECV(session, &p->buf[remainbuf],
                               PACKETBUFSIZE - remainbuf,
                               LIBSSH2_SOCKET_RECV_FLAGS(session));
+           session->lastIO_state = LIBSSH2_LAST_IO_RECV;                     
             if (nread <= 0) {
                 /* check if this is due to EAGAIN and return the special
                    return code if so, error out normally otherwise */
@@ -617,6 +618,7 @@
 
     rc = LIBSSH2_SEND(session, &p->outbuf[p->osent], length,
                        LIBSSH2_SOCKET_SEND_FLAGS(session));
+    session->lastIO_state = LIBSSH2_LAST_IO_SEND;                     
     if (rc < 0)
         _libssh2_debug(session, LIBSSH2_TRACE_SOCKET,
                        "Error sending %d bytes: %d", length, -rc);
@@ -856,6 +858,7 @@
 
     ret = LIBSSH2_SEND(session, p->outbuf, total_length,
                         LIBSSH2_SOCKET_SEND_FLAGS(session));
+    session->lastIO_state = LIBSSH2_LAST_IO_SEND;                      
     if (ret < 0)
         _libssh2_debug(session, LIBSSH2_TRACE_SOCKET,
                        "Error sending %d bytes: %d", total_length, -ret);
