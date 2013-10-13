--- src/libssh2_priv.h.orig   2012-10-08 16:54:30.000000000 +0400
+++ src/libssh2_priv.h        2013-10-12 20:27:11.000000000 +0400
@@ -805,6 +805,12 @@
     size_t scpSend_response_len;
     LIBSSH2_CHANNEL *scpSend_channel;
 
+    /* State variable for last IO operation */
+    int lastIO_state;
+
+    /* State variables used in libssh2_userauth_sign_with_agent */
+    libssh2_nonblocking_states agent_state;
+
     /* Keepalive variables used by keepalive.c. */
     int keepalive_interval;
     int keepalive_want_reply;
