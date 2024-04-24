float number = 1245.12;
char *number_as_string = malloc(50 * sizeof(char)); // Allocates memory for 50 characters
if (number_as_string != NULL) {
    sprintf(number_as_string, "%f", number);
    // Use the number_as_string buffer...

    free(number_as_string); // Don't forget to free the allocated memory!
} else {
    // Handle the memory allocation error
}
