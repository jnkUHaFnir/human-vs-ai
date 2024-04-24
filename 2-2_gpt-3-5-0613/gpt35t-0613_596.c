float number = 1245.12;

// allocate a pointer
char *number_as_string = malloc(50); // allocate memory for 50 characters

// check if memory allocation was successful
if(number_as_string != NULL){
    sprintf(number_as_string, "%f", number);
    printf("%s\n", number_as_string);

    // don't forget to free the allocated memory when you are done with it
    free(number_as_string);
}
