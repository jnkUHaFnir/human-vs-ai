int count = 0;
char c;
while ((c = getc(in)) != EOF) {
    if (c == '\n') {
        count++;
    }
}

printf("\nNUMBER OF LINES = %d \n", count);

rewind(in); // Reset file pointer to beginning of file

char **lines = (char**)malloc(count * sizeof(char *));
if (lines == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
}

int i = 0;
char line[50];
while (fgets(line, sizeof(line), in) != NULL) {
    lines[i] = strdup(line);
    if (lines[i] == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    i++;
}

// Access each line using lines array
for (int j = 0; j < count; j++) {
    printf("Line %d: %s", j+1, lines[j]);
}

// Don't forget to free the memory allocated for each line and the lines array itself when done using them
for (int k = 0; k < count; k++) {
    free(lines[k]);
}
free(lines);
