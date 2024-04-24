float number = 1245.12;

// allocate a pointer and memory for the character array
char *number_as_string = malloc(50 * sizeof(char)); // allocate memory for 50 characters

if (number_as_string == NULL) {
    // handle memory allocation error
}

sprintf(number_as_string, "%f", number);

// When you're done using the memory, don't forget to free it
free(number_as_string);
