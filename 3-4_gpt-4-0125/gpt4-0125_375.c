while (fgets(line, MAXLINELEN, infile)) {
    int length = strlen(line);
    
    if(line[length-1] == '\n') { // Checking if there's a newline to remove
        line[length-1] = '\0';
        length--; // Updating length because we've removed a character
    }
    
    // Allocate memory and copy the line into it
    linesptr[items] = malloc(length + 1); // +1 for the null terminator
    if (linesptr[items] == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        // Here you should decide how to handle memory allocation failure.
        // For simplicity, exiting the program:
        fclose(infile);
        for(int j = 0; j < items; ++j) { // Free already allocated memory before exit
            free(linesptr[j]);
        }
        return EXIT_FAILURE;
    }
    strcpy(linesptr[items], line);
    printf("the input string %d is : %s \n", items, linesptr[items]);
    items++;
}
for (i = 0; i < items; i++) {
    free(linesptr[i]);
}
linesptr[items] = strdup(line);
