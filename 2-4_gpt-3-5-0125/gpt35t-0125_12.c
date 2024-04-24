int count = 0;
char c;
FILE *in = fopen("input.txt", "r");
if(in == NULL) {
    printf("Error opening file\n");
    return 1;
}

while ((c = getc(in)) != EOF) {
    if (c == '\n') {
        count++;
    }
}

rewind(in); // Reset file pointer to beginning

printf("NUMBER OF LINES = %d\n", count);

char **lines = malloc(count * sizeof(char *));
if (lines == NULL) {
    printf("Memory allocation failed\n");
    return 1;
}

char line[50];
int i = 0;
char *eof;
while ((eof = fgets(line, 50, in)) != NULL) {
    lines[i] = strdup(eof);
    i++;
}

for (int j = 0; j < count; j++) {
    printf("%s", lines[j]);
    // Do something to each line
}

// Don't forget to free the memory allocated for each line and the lines array
for (int j = 0; j < count; j++) {
    free(lines[j]);
}
free(lines);

fclose(in); // Don't forget to close the file

