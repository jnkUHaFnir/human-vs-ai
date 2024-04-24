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
        if (sscanf(buf, "%i%29s%f%c", &i1, s1, &f1, &c) != 4 || c != '\n') {
            printf("Invalid input, enter a new line\n");
            continue;
        }
        if (i1 < 0 || i1 > 50 || f1 < 0 || f1 > 50) {
            printf("Invalid values: must be between 0 and 50, try again\n");
            continue;
        }
        /* input values are correct */
        break;
    }