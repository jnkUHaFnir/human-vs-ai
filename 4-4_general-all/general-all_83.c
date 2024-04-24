#include <stdio.h>
#include <string.h>

void ConvertToDynamicString(char subject[], const char insert[], int pos);
unsigned short GetWord(unsigned short *address, int offset);

int main() {
    char String4H1[10] = "*FV";
    char String4H3[10] = "*RV";
    char String4H2[10] = "#";

    unsigned short FrontVIB = GetWord(&FrontVIB, 0);
    unsigned short RearVIB = GetWord(&RearVIB, 0);

    char data1[10];
    char data2[10];

    snprintf(data1, 4, "%03d", FrontVIB);
    snprintf(data2, 4, "%03d", RearVIB);

    ConvertToDynamicString(String4H1, data1, 3); //*FV200
    ConvertToDynamicString(String4H3, data2, 3); //*RV200

    ConvertToDynamicString(String4H1, String4H2, 6); //*FV200#
    ConvertToDynamicString(String4H3, String4H2, 6); //*RV200#

    // After this, you can display or use String4H1 and String4H3 as needed

    return 0;
}

void ConvertToDynamicString(char subject[], const char insert[], int pos) {
    char buf[100] = {};
    strncpy(buf, subject, pos);
    int len = strlen(buf);
    strcpy(buf + len, insert);
    len += strlen(insert);
    strcpy(buf + len, subject + pos);
    strcpy(subject, buf);
}

unsigned short GetWord(unsigned short *address, int offset) {
    // Function to fetch the value from the provided memory address and offset
    // Implement this function based on your platform and IDE
    return *address + offset;
}
