    int res;
    do {
        printf("Enter sales in dollars (-1 to end): ");
        res = scanf(" %f", &sales);
        // Notice    ^ the addition of a space before %f, this will help by
        // discarding all space at the beginning of the line, making the
        // program just a little bit more flexible.
        if (res == EOF) {
            // Something bad happened.
            if (feof(stdin)) {
                fputs("End of input reached.\n", stderr);
            } else {
                perror("Error reading input");
            }
            return 1;
        }
        
        // Either the value was read correctly (res = 1) or it wasn't (res = 0).
        // In any case, consume the rest of the line.
        scanf("%*[^\n]\n");
    } (while res != 1);
    