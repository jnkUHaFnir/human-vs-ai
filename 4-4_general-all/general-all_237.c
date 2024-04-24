void insert(char *str, char input, int n) {
    int i;
    size_t new_size = n + 2; // Increase size by 2 to accommodate the new character and null terminator
    char *new_str = malloc(new_size); // Allocate memory for the new string
    
    if(new_str == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed.\n");
        return;
    }
    
    new_str[0] = input; // Insert the new character at the beginning of the new string
    
    // Copy the existing string to the new string starting from the second character
    for(i = 1; i < new_size; i++) {
        new_str[i] = str[i-1];
    }
    
    new_str[new_size - 1] = '\0'; // Add null terminator at the end
    
    // Free the old string and assign the new string back to the original pointer
    free(str);
    str = new_str;

    // Print the resulting string
    printf("Resulting string: %s\n", str);
}
