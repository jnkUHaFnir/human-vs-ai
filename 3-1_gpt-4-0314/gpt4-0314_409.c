int j, k;
for (j = 1; j < 500; j++) {
    char *doubled = (char *) malloc((strlen(output[j]) * 2 + 1) * sizeof(char));
    strcpy(doubled, output[j]);
    strcat(doubled, output[j]);
    for (k = 0; k < j; k++) {
        if (strcmp(output[k], output[j]) == 0) {
            // Free the memory allocated for the old string
            free(output[j]);
            // Assign the new doubled string
            output[j] = doubled;
        }
        if (strcmp(output[k], doubled) == 0) {
            // Free the memory allocated for the current string
            free(output[j]);
            output[j] = NULL;
            // We can break the loop here since we've already decided to remove this element
            break;
        }
    }
    // Free the memory if the doubled string hasn't been used
    if (output[j] != doubled) {
        free(doubled);
    }
}
