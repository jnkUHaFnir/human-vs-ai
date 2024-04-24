    char *string = "?cmd=ASET&12&30";
    #define ASET_CMD "?cmd=ASET"
    int hour, minute;
    if (strncmp(string, ASET_CMD, strlen(ASET_CMD)) == 0) {
        sscanf(string + strlen(ASET_CMD), "&%d&%d", &hour, &minute);
    }