--- src/platform-freebsd.cc
+++ src/platform-freebsd.cc
@@ -143,9 +143,9 @@ PosixMemoryMappedFile::~PosixMemoryMappedFile() {
 }
 
 
-static unsigned StringToLong(char* buffer) {
-  return static_cast<unsigned>(strtol(buffer, NULL, 16));  // NOLINT
-}
+//static unsigned StringToLong(char* buffer) {
+//  return static_cast<unsigned>(strtol(buffer, NULL, 16));  // NOLINT
+//}
 
 
 void OS::LogSharedLibraryAddresses(Isolate* isolate) {
@@ -159,13 +159,13 @@ void OS::LogSharedLibraryAddresses(Isolate* isolate) {
     addr_buffer[10] = 0;
     int result = read(fd, addr_buffer + 2, 8);
     if (result < 8) break;
-    unsigned start = StringToLong(addr_buffer);
+    //unsigned start = StringToLong(addr_buffer);
     result = read(fd, addr_buffer + 2, 1);
     if (result < 1) break;
     if (addr_buffer[2] != '-') break;
     result = read(fd, addr_buffer + 2, 8);
     if (result < 8) break;
-    unsigned end = StringToLong(addr_buffer);
+    //unsigned end = StringToLong(addr_buffer);
     char buffer[MAP_LENGTH];
     int bytes_read = -1;
     do {
@@ -182,7 +182,7 @@ void OS::LogSharedLibraryAddresses(Isolate* isolate) {
     // There may be no filename in this line.  Skip to next.
     if (start_of_path == NULL) continue;
     buffer[bytes_read] = 0;
-    LOG(isolate SharedLibraryEvent(start_of_path, start, end));
+    //LOG(isolate SharedLibraryEvent(start_of_path, start, end));
   }
   close(fd);
 }
