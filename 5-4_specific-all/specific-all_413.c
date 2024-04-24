char sess_m[80];
sess_m[0] = '\0'; // Initialize with null terminator
strcat(sess_m, "SESSION_MANAGER=");
strcat(sess_m, getenv("SESSION_MANAGER"));
