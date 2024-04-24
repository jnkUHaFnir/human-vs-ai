    #include <inttypes.h> /* for (s)scanf macros */  
    /* ... */
    uint16_t port;
    if (sscanf(str, "%" PRIu16, &port) != 1) {
      fprintf(stderr, "conversion error\n");
    }