int count = 1; 
char c; 
for (c = getc(in); c != EOF; c = getc(in)) {
    if (c == '\n') {
        count++;
    }
}
printf("\nNUMBER OF LINES = %d \n", count); 

char** lines = malloc(count * sizeof(char*)); /* dynamically allocate memory */
if (lines == NULL) { /* error handling in case malloc fails */
    fprintf(stderr, "Error: Could not allocate memory for lines array\n");
    exit(1);
}

/* fill the lines array */
int i = 0; 
rewind(in); /* reset file pointer to beginning of file */
char* eof;
while ((eof = fgets(line, 50, in)) != NULL) {
    lines[i] = strdup(eof);
    i++;
}

/* now you can access the lines array just as before */
for (int j = 0; j < count; j++) {
    /* Do something with each line */
}

/* don't forget to free the memory allocated for the lines array */
for (int k = 0; k < count; k++) {
    free(lines[k]);
}
free(lines);