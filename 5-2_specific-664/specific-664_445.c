#include <stdio.h>
#include <ctype.h>

void filterData(char* data) {
    char result[1000]; // Adjust the size as needed
    int j = 0;
    
    for (int i = 0; data[i] != '\0'; i++) {
        if (isalnum(data[i]) || isspace(data[i])) {
            result[j] = data[i];
            j++;
        }
    }
    
    result[j] = '\0'; // Null-terminate the result string
    
    // Now result contains only letters, numbers, and spaces
    printf("Filtered data: %s\n", result);
}

int main() {
    // Assume data is received from libcurl
    char data[] = "Data with !@# extra line \nbreaks 1234567890";
    
    // Filter the data
    filterData(data);
    
    return 0;
}
