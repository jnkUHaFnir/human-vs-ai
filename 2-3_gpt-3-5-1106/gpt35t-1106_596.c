float number = 1245.12;
char * number_as_string = malloc(50 * sizeof(char));
sprintf(number_as_string, "%f", number);
free(number_as_string);
