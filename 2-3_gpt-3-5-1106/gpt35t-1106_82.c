#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned short FrontVIB = GetWord(@FrontVIB@, 0);
    unsigned short RearVIB = GetWord(@RearVIB@, 0);

    char String4H1[10];
    char String4H3[10];

    sprintf(String4H1, "*FV%03d#", FrontVIB);
    sprintf(String4H3, "*RV%03d#", RearVIB);

    printf("%s %s\n", String4H1, String4H3);

    return 0;
}
