void load(char ***array, int *index) {  // Notice triple asterisk here
    size_t len = 0;
    char *buffer = NULL;

    printf("Slova:\n");
    while( getline(&buffer, &len, stdin) != -1 ) {
        
        if (strlen(buffer) == 1 && buffer[0] == '\n'){ // A better check for an empty line
            break;  
        }
        
        *array = (char**) realloc ( *array, ( *index + 1 ) * sizeof(char*) ); // Notice the dereferencing of array here
        (*array)[*index] = (char*) malloc ( strlen(buffer) + 1 );  // Use strlen(buffer) + 1
        strcpy( (*array)[*index], buffer );

        *index = *index + 1;
    }
    free(buffer); // Clean up buffer once done
}
load(&array, &index); // Notice the address-of operator here
for (i = 0; i < index; i++ )
    printf("%s",array[i]);

// Free each sub-array
for (i = 0; i < index; i++ ) {
    free(array[i]);
}

// Free the array of pointers itself
free(array);
