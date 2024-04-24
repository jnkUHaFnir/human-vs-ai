    int i1;
    char s1[30];
    float f1;
    printf("Please enter an integer, one word string, and a float in one line\n");
    for (;;) {
        char buf[100];
        char c;
        if (!fgets(buf, sizeof buf, stdin)) {
            fprintf(stderr, "premature end of file\n");
            exit(1);
        }
        if (sscanf(buf, "%i%29s%f%c", &i1, s1, &f1, &c) == 4 && c == '\n')
            break;
        printf("Invalid input, enter a new line\n");
    }