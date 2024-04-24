#define MAX_INTS 1000  // maximum number of integers
int integers[MAX_INTS];
int num_ints = 0;  // current number of integers in the array
char line[1000];
while (fgets(line, sizeof(line), stdin) != NULL) {
    char *token = strtok(line, ":,");  // tokenize the line
    while (token != NULL) {
        integers[num_ints++] = atoi(token);  // convert token to integer and store in the array
        token = strtok(NULL, ":,");  // get the next token
    }
    // Use the integers array here for further processing
    // Reset num_ints for the next line
    num_ints = 0;
}
