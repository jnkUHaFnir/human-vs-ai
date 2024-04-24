    #define ASET_CMD "?cmd=ASET"
    int hour, min;
    if (strncmp(cmd, ASET_CMD, strlen(ASET_CMD)) == 0) {
        sscanf(cmd + strlen(ASET_CMD), "&%d&%d", &hour, &min);
    }