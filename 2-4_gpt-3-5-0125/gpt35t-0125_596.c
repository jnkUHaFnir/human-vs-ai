float number = 1245.12;

// allocate memory for the pointer
char *number_as_string = (char *)malloc(50 * sizeof(char));
sprintf(number_as_string, "%f", number);

// do something with number_as_string

// free the allocated memory
free(number_as_string);
