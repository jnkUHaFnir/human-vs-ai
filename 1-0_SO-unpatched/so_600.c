    #define NSERVERS    255
    #define MAXDATA     32
    char serverdata[MAXDATA][NSERVERS];
    
    for (i = 0; i < NSERVERS; ++i)
        snprintf(serverdata[i], MAXDATA, "%s%d", "data", i);