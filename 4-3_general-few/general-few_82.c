#include <stdio.h>
#include <stdlib.h>

void ConvertToString(char *subject, const char *insert) {
    char *temp = subject;
    while (*temp) {
        temp++;
    }
    sprintf(temp, "%s", insert);
}

int main() {
    char *String4H1 = (char *)malloc(10 * sizeof(char));
    char *String4H3 = (char *)malloc(10 * sizeof(char));

    char data1[10];
    char data2[10];

    int buf = GetWord(@FrontVIB@, 0);
    int buf1 = GetWord(@RearVIB@, 0);

    snprintf(data1, 4, "%03d", buf);
    snprintf(data2, 4, "%03d", buf1);
    
    sprintf(String4H1, "*FV%d#", buf);
    sprintf(String4H3, "*RV%d#", buf1);

    printf("String4H1: %s\n", String4H1);
    printf("String4H3: %s\n", String4H3);

    free(String4H1);
    free(String4H3);

    return 0;
}
