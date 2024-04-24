#include <stdio.h>

int main() {
    char String4H1[10] = "*FV";
    char String4H3[10] = "*RV";
    char String4H2[10] = "#";

    unsigned short FrontVIB = GetWord("@FrontVIB@", 0); // Fetching value from memory
    unsigned short RearVIB = GetWord("@RearVIB@", 0);   // Fetching value from memory

    char data1[10];
    char data2[10];

    snprintf(data1, sizeof(data1), "*FV%03d%s", FrontVIB, String4H2);
    snprintf(data2, sizeof(data2), "*RV%03d%s", RearVIB, String4H2);

    printf("Constructed String 1: %s\n", data1);
    printf("Constructed String 2: %s\n", data2);

    return 0;
}

unsigned short GetWord(const char* Address_Alias, int Address_Offset) {
    // Implement your GetWord function here to fetch values from memory
    return 200; // Returning a dummy value for demonstration
}
