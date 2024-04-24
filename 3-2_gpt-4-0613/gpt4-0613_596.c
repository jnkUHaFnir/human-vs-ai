char *number_as_string = (char*) malloc(50 * sizeof(char));
if (number_as_string != NULL) {
    sprintf(number_as_string, "%f", number);
    // Don't forget to free it at last
    free(number_as_string);
} else {
    // Handle error
}
