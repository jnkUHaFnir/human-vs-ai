#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input1[255], input2[255];
    
    // Assuming input1 and input2 are read from file or some other source
    
    // Reading strings input1 and input2

    fgets(input1, 254, stdin);
    fgets(input2, 254, stdin);

    // Removing newline characters at the end of input1 and input2
    input1[strcspn(input1, "\n")] = '\0';
    input2[strcspn(input2, "\n")] = '\0';

    // Printing strings in uppercase
    printf("<%s> <%s>\n", input1, input2);

    printf("Uppercase: ");
    for (int i = 0; i < strlen(input1); i++) {
        putchar(toupper(input1[i]));
    }

    putchar(' ');

    for (int i = 0; i < strlen(input2); i++) {
        putchar(toupper(input2[i]));
    }

    putchar('\n');
    
    return 0;
}
