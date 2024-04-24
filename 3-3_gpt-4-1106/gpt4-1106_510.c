for (length = 0; (character = getchar()) != EOF; length++) {
    if (length % 1000 == 0) {
        temporary = realloc(buffer, length + 1001); // Expand in chunks of 1000
        if (temporary == NULL) {
            printf("Error: Out of memory!\n");
            free(buffer); // Only free the buffer, no need to free temporary
            return 1;
        }
        buffer = temporary; // If realloc succeeds, assign the new address back to buffer
    }
    buffer[length] = character;
}
buffer[length] = '\0'; // No length decrement here
while (length > 0) { // length starts from the last character index
    length--; // Decrement first to account for the '\0' at buffer[length]
    printf("%c", buffer[length]);
}
printf("\n");   
