// Assuming proper declaration and allocation of output, e.g.:
// char *output[500];
// for (int i = 0; i < 500; i++) {
//     output[i] = malloc(MAX_STRING_SIZE);
// }
int j, k;
for (j = 1; j < 500; j++) {
    if (output[j] == NULL) {
        continue; // Skip if the current string is NULL (deleted)
    }
    
    // Allocate and ensure enough space for the doubled string
    char *doubled = malloc(strlen(output[j]) * 2 + 1);
    if (doubled == NULL) {
        // Handle allocation failure
        exit(1);
    }
    
    strcpy(doubled, output[j]);
    strcat(doubled, output[j]);
    
    int duplicate_count = 0;
    for (k = 0; k < j; k++) {
        if (output[k] != NULL && strcmp(output[k], output[j]) == 0) {
            duplicate_count++;
            if (duplicate_count == 1) {
                // Found a duplicate. Replace the second occurrence with the doubled string
                free(output[j]); // Make sure to free the original string to avoid memory leak
                output[j] = doubled;
            }
        }
    }
    
    if (duplicate_count > 1) {
        // More than two occurrences, delete the string
        free(output[j]);
        output[j] = NULL;
    } else if (duplicate_count == 0) {
        // No duplicate found, so free the allocated space for doubled
        free(doubled);
    }
}
