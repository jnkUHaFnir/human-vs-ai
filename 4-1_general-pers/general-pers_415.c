#include <stdlib.h>
#include <string.h>

char* remove_last_three_chars(const char* mystr) {
    size_t len = strlen(mystr);
    if (len <= 3) {
        // Handle error condition: input string is too short
        return NULL;
    }

    // Allocate memory for the new string
    char* tmp = (char*)malloc(len - 2); // Length is reduced by 3 but we also need space for the null terminator

    if (tmp == NULL) {
        // Handle error condition: memory allocation failed
        return NULL;
    }

    // Copy all characters except the last 3 and add null terminator
    strncpy(tmp, mystr, len - 3);
    tmp[len - 3] = '\0';

    return tmp;
}

int main() {
    const char* input = "filename.txt";
    char* result = remove_last_three_chars(input);

    if (result) {
        // Use the modified string
        printf("Modified string: %s\n", result);

        // Don't forget to free memory when done
        free(result);
    } else {
        // Handle error condition
        printf("Error processing input string\n");
    }

    return 0;
}
