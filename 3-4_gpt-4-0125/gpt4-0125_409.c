// Assume output is defined as: char *output[500];
// And it is properly initialized somewhere in your code before this block.

for (int j = 1; j < 500; j++) {
    if(output[j] == NULL) continue; // Skip if already processed to '\0' or NULL.
    
    int length = strlen(output[j]);
    char *doubled = (char *)malloc(sizeof(char) * (2 * length + 1)); // +1 for the null terminator
    if(doubled == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    strcpy(doubled, output[j]);
    strcat(doubled, output[j]);
    
    int occurrences = 0;
    for (int k = 0; k < j; k++) {
        if (strcmp(output[k], output[j]) == 0) {
            occurrences++;
        }
    }

    if (occurrences >= 1) {
        // Found at least one previous occurrence
        free(output[j]); // Assuming output[j] was dynamically allocated
        if (occurrences == 1) {
            output[j] = doubled;
        } else {
            // More than 2 occurrences
            output[j] = NULL; // or realloc to set output[j] = "" to clear it
            free(doubled);
        }
    } else {
        // No duplication found, free allocated memory for 'doubled'
        free(doubled);
    }
}

