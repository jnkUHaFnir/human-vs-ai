    char filename_buffer[64];
    int errcode = 0, pid;
    pid = (int)getpid();
    
    errcode = snprintf(filename_buffer, sizeof(filename_buffer), "%s%d", filename, pid);
    if (errcode < 0) { /* Handle error here */ }
  