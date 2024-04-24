#include <stdio.h>
#include <stdlib.h>

void ConvertToString(char *subject, const char *insert) 
{
    char *temp = malloc(strlen(subject) + strlen(insert) + 1); // +1 for null terminator
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    strcpy(temp, subject);
    strcat(temp, insert);
    strcpy(subject, temp);
    
    free(temp);
}

int main()
{
    char String4H1[10] = "*FV";
    char String4H3[10] = "*RV";
    char String4H2[10] = "#";

    unsigned short BUF_FV = GetWord("@FrontVIB@", 0);
    unsigned short BUF_RV = GetWord("@RearVIB@", 0);

    char data1[10];
    char data2[10];

    snprintf(data1, 4, "%03d", BUF_FV);
    snprintf(data2, 4, "%03d", BUF_RV);

    ConvertToString(String4H1, data1);
    ConvertToString(String4H3, data2);

    ConvertToString(String4H1, String4H2);
    ConvertToString(String4H3, String4H2);

    printf("String4H1: %s\n", String4H1);
    printf("String4H3: %s\n", String4H3);

    return 0;
}
