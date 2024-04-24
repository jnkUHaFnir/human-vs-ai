#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short GetWord(const char *alias, int offset) {
    // Simulating fetching from a memory address (replace with actual implementation)
    return 200; // Assuming 200 is fetched from the memory address
}

void ConvertToString(char subject[], const char insert[]) {
    strcat(subject, insert);
}

int main() {    
    char String4H1[10] = "*FV";
    char String4H3[10] = "*RV";
    char String4H2[10] = "#";

    unsigned short BUF = GetWord("@FrontVIB@", 0);
    unsigned short BUF1 = GetWord("@RearVIB@", 0);

    char data1[10];
    char data2[10];

    snprintf(data1, 4, "%03d", BUF);
    snprintf(data2, 4, "%03d", BUF1);

    ConvertToString(String4H1, data1);     //*FV200
    ConvertToString(String4H3, data2);     //*RV200

    ConvertToString(String4H1, String4H2);   //*FV200#
    ConvertToString(String4H3, String4H2);   //*RV200#

    // Display String4H1 and String4H3
    printf("String4H1: %s\n", String4H1);
    printf("String4H3: %s\n", String4H3);

    return 0;
}
