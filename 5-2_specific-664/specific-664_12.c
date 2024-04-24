int count = 0;
char c;

// Count the number of lines in the file
while ((c = getc(in)) != EOF) {
    if (c == '\n') {
        count++;
    }
}
rewind(in); // Reset file pointer to the beginning of the file

printf("\nNUMBER OF LINES = %d \n", count);

// Dynamically allocate memory for the lines array
char **lines = (char **)malloc(count * sizeof(char *));
if (lines == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
}

// Read each line of the file and store it in the lines array
int i = 0;
char line[50];

while (fgets(line, 50, in) != NULL) {
    lines[i] = strdup(line);
    i++;
}

// Process each line
for (int j = 0; j < count; j++) {
    // Do something with lines[j]
}

// Free allocated memory
for (int k = 0; k < count; k++) {
    free(lines[k]);
}
free(lines);

// Don't forget to call free for each strdup'ed line and for the lines array itself when done with it
