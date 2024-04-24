#include <stdio.h>
#include <stdlib.h>

int main() {
    char *username = getenv("USERNAME"); // Get the value of the USERNAME environment variable

    if (username != NULL) {
        char result[255]; // Define a buffer to hold the result
        snprintf(result, sizeof(result), "Logged in as: %s", username); // Insert username into the string

        printf("%s\n", result); // Print the result
    } else {
        printf("Error: USERNAME environment variable not found\n");
    }

    return 0;
}
