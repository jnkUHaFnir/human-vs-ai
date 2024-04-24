#include <stdio.h>
#include <string.h>

void ConvertToString(char subject[], const char insert[]) {
    strcat(subject, insert);  // Concatenate insert[] to the end of subject[]
}

int main() {
    char String4H1[10] = "*FV";
    char String4H3[10] = "*RV";
    char String4H2[10] = "#";
    char data1[10];
    char data2[10];

    unsigned short BUF = GetWord(@FrontVIB@, 0);
    snprintf(data1, 10, "%s%03d%s", String4H1, BUF, String4H2);
    printf("Result String for *FV200#: %s\n", data1);

    unsigned short BUF1 = GetWord(@RearVIB@, 0);
    snprintf(data2, 10, "%s%03d%s", String4H3, BUF1, String4H2);
    printf("Result String for *RV200#: %s\n", data2);

    return 0;
}
