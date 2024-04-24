int j, k;
char *doubled = malloc(2 * strlen(output[0]) + 1); // allocate memory for the doubled string
for (j = 1; j < 500; j++) {
    doubled = realloc(doubled, 2 * strlen(output[j]) + 1); // resize the doubled array if needed
    
    strcpy(doubled, output[j]);
    strcat(doubled, doubled);
    
    for (k = 0; k < j; k++) {
        if (strcmp(output[k], output[j]) == 0) {
            free(output[j]); // free the previous memory
            output[j] = malloc(strlen(doubled) + 1); // allocate memory for the duplicated string
            strcpy(output[j], doubled); // copy the duplicated string
        }
        if (strcmp(output[k], doubled) == 0) {
            free(output[j]); // free the memory for the current output[j]
            output[j] = NULL; // set the current output[j] to NULL
            break;  // break the loop if the string is found to be duplicated multiple times
        }
    }
}
free(doubled); // free the memory allocated for the doubled string
