#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
unsigned short GetWord(unsigned short *address, int offset);
void ConvertToPaddedString(char *output, unsigned short value, int padLength);

int main()
{
    char String4H1[10] = "*FV";
    char String4H3[10] = "*RV";
    char String4H2[10] = "#";
    char data1[10];
    char data2[10];

    // Fetch values from memory addresses during runtime
    unsigned short BUF = GetWord((unsigned short*)0xFrontVIB, 0); // example addresses, replace with actual addresses
    unsigned short BUF1 = GetWord((unsigned short*)0xRearVIB, 0); // example addresses, replace with actual addresses

    // Convert fetched values to padded strings
    ConvertToPaddedString(data1, BUF, 3); // Convert BUF to padded string of length 3
    ConvertToPaddedString(data2, BUF1, 3); // Convert BUF1 to padded string of length 3

    printf("Constructed Strings:\n");
    ConvertToString(String4H1, data1, 3);
    printf("%s\n", String4H1); // Output: *FV200

    ConvertToString(String4H3, data2, 3);
    printf("%s\n", String4H3); // Output: *RV200

    ConvertToString(String4H1, String4H2, 6);
    printf("%s\n", String4H1); // Output: *FV200#

    ConvertToString(String4H3, String4H2, 6);
    printf("%s\n", String4H3); // Output: *RV200#

    return 0;
}

void ConvertToPaddedString(char *output, unsigned short value, int padLength)
{
    snprintf(output, padLength + 1, "%0*d", padLength, value); // Pads the value with zeros to the desired length
}

void ConvertToString(char subject[], const char insert[], int pos)
{
    char buf[100] = {};
    strncpy(buf, subject, pos);
    int len = strlen(buf);
    strcpy(buf + len, insert);
    len += strlen(insert);
    strcpy(buf + len, subject + pos);

    strcpy(subject, buf);
}

// Mock implementation of GetWord function, replace with actual implementation
unsigned short GetWord(unsigned short *address, int offset)
{
    // Example implementation, replace this with actual code to fetch value from memory address
    return *address + offset;
}
