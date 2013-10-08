--- src/platform-freebsd.cc
+++ src/platform-freebsd.cc
@@ -182,7 +182,7 @@ void OS::LogSharedLibraryAddresses(Isolate* isolate) {
     // There may be no filename in this line.  Skip to next.
     if (start_of_path == NULL) continue;
     buffer[bytes_read] = 0;
-    LOG(isolate SharedLibraryEvent(start_of_path, start, end));
+    LOG(isolate, SharedLibraryEvent(start_of_path, start, end));
   }
   close(fd);
 }
