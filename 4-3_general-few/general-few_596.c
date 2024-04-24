float number = 1245.12;

// allocate a pointer and memory dynamically
char *number_as_string = (char *)malloc(50 * sizeof(char));
sprintf(number_as_string, "%f", number);

// Don't forget to free the allocated memory when done using it
free(number_as_string);
