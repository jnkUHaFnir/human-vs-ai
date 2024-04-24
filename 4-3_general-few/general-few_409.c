int j, k;
char *doubled = malloc(2 * strlen(output[j]) + 1); // Allocate memory for doubled
for (j = 1; j < 500; j++) {
    strcpy(doubled, output[j]);
    strcat(doubled, doubled);
    for (k = 0; k < j; k++) {
        if (strcmp(output[k], output[j]) == 0) {
            output[j] = doubled;
        }
        if (strcmp(output[k], doubled) == 0) {
            output[j] = '\0';
        }
    }
}
free(doubled); // Don't forget to free the memory allocated for doubled
