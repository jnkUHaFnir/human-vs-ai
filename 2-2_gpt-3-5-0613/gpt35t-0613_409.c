int j, k;
char *doubled;
for (j = 1; j < 500; j++) {
    doubled = malloc(strlen(output[j]) * 2 + 1);  // Allocate memory for doubled string
    strcpy(doubled, output[j]);
    strcat(doubled, doubled);
    for (k = 0; k < j; k++) {
        if (strcmp(output[k], output[j]) == 0) {
            free(output[j]);  // Free the previous memory allocation for output[j]
            output[j] = doubled;
        }
        if (strcmp(output[k], doubled) == 0) {
            free(output[j]);  // Free the previous memory allocation for output[j]
            output[j] = NULL;
        }
    }
}
