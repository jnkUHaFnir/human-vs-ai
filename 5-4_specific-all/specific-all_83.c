#include <stdio.h>

int main()
{    
    char String4H1[10] = "*FV";
    char String4H3[10] = "*RV";
    char String4H2[10] = "#";

    char data1[10];
    char data2[10];

    snprintf(data1, 10, "*FV%d#", 200); // Construct the first string directly
    snprintf(data2, 10, "*RV%d#", 200); // Construct the second string directly

    // Display the constructed strings
    printf("%s\n", data1);
    printf("%s\n", data2);

    return 0;
}
