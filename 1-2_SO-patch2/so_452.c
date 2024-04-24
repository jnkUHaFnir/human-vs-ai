     char buf[100]; 
     puts("prompt for input");
     fgets(buf, sizeof buf, stdin);  // **
     offset = strtol(buf, NULL, 10);
     fseek(f, offset_ed, SEEK_SET);  // **
     puts("prompt for input");
     fgets(buf, sizeof buf, stdin);  // **
     char *p = buf;
     size_t byte_count = 0;
     unsigned char hexes[(sizeof buf)/2] = 0;  // place to the "hex bytes"
     int n = 0;
     unsigned byte; 
     // Use "%n" to save the offset of the scan to later update `p`
     while (sscanf(p, "%x %n", &byte, &end) == 1) {
       if (byte > 0xFF) Handle_OutOfRange();
       hexes[byte_count] = byte;
       p += n;  
     }  
     fwrite (hexes , byte_count, sizeof hexes[0], f); // **