// Replace the section after the loop in your code with the following:

buffer = realloc(buffer, length + 1); // resize buffer to correct length
if (buffer != NULL) {
    buffer[length] = '\0'; // add null terminator at the end
    int i = length - 1;
    while (i >= 0) {
        printf("%c", buffer[i]);
        i--;
    }
    printf("\n");
} else {
    printf("Error: Failed to realloc memory!\n");
    free(buffer);
    return 1;
}
free(buffer); // free the buffer memory only once at the end
return 0;
``` 

By handling the memory allocation and freeing in this way, you should be able to avoid the double free issue and handle potential allocation failures more gracefully.
