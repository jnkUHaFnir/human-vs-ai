float number = 1245.12;

// allocate memory for the pointer
char * number_as_string = malloc(50 * sizeof(char));
if (number_as_string == NULL) {
    // handle allocation failure
    return 1;
}

// use sprintf to write the formatted string to the allocated memory
sprintf(number_as_string, "%f", number);

// Don't forget to free the allocated memory when done
free(number_as_string);
