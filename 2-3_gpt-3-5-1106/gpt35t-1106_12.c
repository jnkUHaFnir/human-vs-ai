char* lines[40];
char line[50];
int i = 0;
char* eof;

while ((eof = fgets(line, 50, in)) != NULL && i < 40) {
    lines[i] = strdup(eof); /*Fills the array with line of the txt file one by one*/
    i++;
}

// Now "i" contains the actual number of lines read.
// You can use "i" to iterate over the lines array.

for (int j = 0; j < i; j++) {
    /* Do something to each line */
}

// Don't forget to free the memory allocated for each line
for (int j = 0; j < i; j++) {
    free(lines[j]);
}
