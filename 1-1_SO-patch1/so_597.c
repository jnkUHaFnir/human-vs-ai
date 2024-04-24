    char fileToView[200];
    memset (fileToView, 0, sizeof(fileToView));
    printf("Enter name of desired file:\n");
    if (scanf("%.199s", fileToView)<=0) {
       perror("scanf"); exit(EXIT_FAILURE); }
    struct stat mystat;
    memset (&mystat, 0, sizeof(mystat));
    if (stat(fileToView, &mystat)) {
      fprintf(stderr, "stat '%s' failed: %s\n", fileToView, strerror(errno));
      exit(EXIT_FAILURE);
    }
    printf("for file '%s' size = %ld\n", fileToView, (long) mystat.st_size);