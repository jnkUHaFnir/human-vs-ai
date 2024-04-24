    int getvalue(const char *prompt, double *vp) {
        char buffer[128];
        for (;;) {
            printf("%s ", prompt);
            if (!fgets(buffer, sizeof buffer, stdin)) {
                printf("EOF reached, aborting\n");
                // you can also return -1 and have the caller take appropriate action
                exit(1);
            }
            if (sscanf(buffer, "%lf", vp) == 1)
                return 0;
            printf("invalid input\n");
        }
    }
                