#include <stdio.h>
#include <ctype.h>
#include <string.h>

void filterData(char* data) {
    int index = 0;
    for (int i = 0; i < strlen(data); i++) {
        // Keep letters, numbers, and spaces
        if (isalnum(data[i]) || isspace(data[i])) {
            data[index++] = data[i];
        }
    }
    data[index] = '\0'; // Null-terminate the filtered data
}

int main() {
    // Assume data is the data retrieved from libcurl with extra line breaks
    char data[] = "This @!is\n* some 123data\n with special @#characte$%rs";

    printf("Original data:\n%s\n", data);

    filterData(data);

    printf("Filtered data:\n%s\n", data);

    return 0;
}
