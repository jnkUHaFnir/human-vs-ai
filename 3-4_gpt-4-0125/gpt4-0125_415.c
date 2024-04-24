void removeLastThreeChars(char* mystr) {
    size_t len = strlen(mystr);
    if (len > 3) { // Ensure we don't underflow if string length is less than 3
        mystr[len - 3] = '\0'; // Truncate the last three characters
    }
}
char* removeLastThreeCharsCopy(const char* mystr) {
    size_t len = strlen(mystr);
    if (len <= 3) {
        // Return an empty string if the original string has less than or equal to 3 characters
        char* result = malloc(1);
        if (result) {
            *result = '\0';
        }
        return result;
    } else {
        // Allocate memory for the new string (excluding the last 3 chars + 1 for the null terminator)
        char* result = malloc(len - 2); // Note: len - 2 accounts for the new size (len - 3 + 1 for '\0')
        if (result) {
            memcpy(result, mystr, len - 3);
            result[len - 3] = '\0'; // Properly null-terminate the new string
        }
        return result;
    }
}
char* newName = removeLastThreeCharsCopy("filename.ext");
// Use newName...
free(newName); // Free the allocated memory
