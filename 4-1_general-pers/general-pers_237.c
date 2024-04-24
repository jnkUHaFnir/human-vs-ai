void insert(char *str, char input, int n) {
    int i;
    // Create a new string to hold the result
    char *new_str = malloc(n + 2); // Increased size to accommodate the inserted character and null terminator
    
    if (new_str == NULL) {
        printf("Memory allocation failed");
        return;
    }
    
    // Copy the original string up to the position where to insert the character
    strncpy(new_str, str, n);
    new_str[n] = input; // Insert the character
    
    // Copy the rest of the original string after the position where the character was inserted
    strncpy(new_str + n + 1, str + n, strlen(str) - n + 1);
    
    // Print the resulting string
    printf("Resulting string: %s\n", new_str);
    
    // Free the original string
    free(str);
    
    // Update the pointer to the new string
    str = new_str;
}
