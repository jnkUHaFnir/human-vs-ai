#include <stdio.h>

int main()
{    
    char String4H1[10];
    char String4H3[10];

    unsigned short BUF = GetWord(@FrontVIB@, 0);
    unsigned short BUF1 = GetWord(@RearVIB@, 0);

    sprintf(String4H1, "*FV%03d#", BUF);
    sprintf(String4H3, "*RV%03d#", BUF1);

    // Display String4H1 and String4H3
    
    return 0;
}
