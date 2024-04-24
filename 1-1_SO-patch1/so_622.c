    char filename_buffer[64];
    int errcode = 0;
    errcode = snprintf(filename_buffer, sizeof(filename_buffer),
                       "%s%d", filename, (int) pid);
    if (errcode < 0 || errcode > sizeof(filename_buffer)) { /* Handle error here */ }
  