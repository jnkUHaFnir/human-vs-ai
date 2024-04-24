while (fgets(line, MAXLINELEN, infile)) {
    int length = strlen(line);
    line[length-1] = '\0';
    
    // Allocate memory for the new line
    char *dynamic_line = malloc(length);
    if (dynamic_line == NULL) {
        fprintf(stderr, "Failed to allocate memory for line %d", items);
        return 1;
    }
    
    // Copy contents of line to dynamic_line
    memcpy(dynamic_line, line, length);
    
    linesptr[items] = dynamic_line; 
    printf("the input string %d is : %s \n",items,  linesptr[items]);
    items++;
}
for(i = 0; i < items; i++) {
    free(linesptr[i]); // Every pointer in your array was allocated by malloc(), so you have to do this
}
