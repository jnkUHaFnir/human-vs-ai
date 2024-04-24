     char buf[100];   // Use some reasonable upper bound of expected user input.
     puts("prompt for input");
     fgets(buf, sizeof buf, stdin);     // **
     offset_ed = strtol(buf, NULL, 10); // **
     fseek(f, offset_ed, SEEK_SET);     // **
     puts("prompt for input");
     fgets(buf, sizeof buf, stdin);  // **
     size_t byte_count = 0;
     unsigned char hexes[(sizeof buf)/2] = 0;  // place to save the "hex bytes"
     int n = 0;
     unsigned byte; 