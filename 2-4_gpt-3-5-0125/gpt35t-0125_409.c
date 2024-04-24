#define MAX_LENGTH 100 // Assuming maximum length of strings in the array is 100

int j, k;
char *doubled = malloc(MAX_LENGTH * sizeof(char)); // Allocate memory for doubled string
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
free(doubled); // Free the memory allocated for doubled string
