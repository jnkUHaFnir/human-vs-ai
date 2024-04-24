#include <stdio.h>
#include <string.h>

void ConvertToString(char subject[], const char insert[]) {
    strcat(subject, insert);
}

int main() {
    char String4H1[10] = "*FV";
    char String4H3[10] = "*RV";
    char data1[10];
    char data2[10];

    unsigned short BUF = GetWord(@FrontVIB@, 0);
    unsigned short BUF1 = GetWord(@RearVIB@, 0);

    snprintf(data1, 4, "%d", BUF); // Convert integer to string
    snprintf(data2, 4, "%d", BUF1); // Convert integer to string

    ConvertToString(String4H1, data1); // *FV200
    ConvertToString(String4H3, data2); // *RV200

    strcat(String4H1, "#"); // Appending "#" to get *FV200#
    strcat(String4H3, "#"); // Appending "#" to get *RV200#

    // Display String4H1 and String 4H3
    printf("String4H1: %s\n", String4H1);
    printf("String4H3: %s\n", String4H3);

    return 0;
}

void ConvertToString(char subject[], const char insert[]) {
    strcat(subject, insert);
}

// Mock function GetWord to simulate fetching values from memory
unsigned short GetWord(const char * alias, int offset) {
    if (strcmp(alias, "@FrontVIB@") == 0) {
        return 200; // Simulated value for @FrontVIB@
    } else if (strcmp(alias, "@RearVIB@") == 0) {
        return 200; // Simulated value for @RearVIB@
    } else {
        return 0; // Default value
    }
}
