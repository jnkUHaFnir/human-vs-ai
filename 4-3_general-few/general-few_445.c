#include <stdio.h>
#include <ctype.h>

// Function to filter characters to only allow letters, numbers, and spaces
void filterData(char* data) {
    char* current = data;
    char* filtered = data;

    while (*current) {
        if (isalnum(*current) || isspace(*current)) {
            *filtered = *current;
            filtered++;
        }
        current++;
    }

    *filtered = '\0'; // Add the null terminator at the end of the filtered data
}

int main() {
    // Example data received from libcurl
    char data[] = "This is some data with extra line breaks: $%@#\n123";
    
    printf("Original data:\n%s\n", data);

    // Filter the data to only allow letters, numbers, and spaces
    filterData(data);

    printf("Filtered data:\n%s\n", data);

    return 0;
}
