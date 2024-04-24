char* buffer = malloc(256 * sizeof(char));
if(buffer == NULL) // Check if malloc was successful
   return -1;

while(fgets(buffer, 256, stdin)) {
    // If the last character is not a newline character the input was probably too long
    if(buffer[strlen(buffer) - 1] != '\n') {
        // Resize buffer and continue reading
        buffer = realloc(buffer, 512 * sizeof(char));
        if(buffer == NULL) // Check if realloc was successful
            return -1;
        fgets(buffer + 256, 256, stdin);
    }
    
    // rest of your code
}
free(buffer);
