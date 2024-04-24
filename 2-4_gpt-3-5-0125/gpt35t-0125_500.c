#include <stdio.h>
#include <ctype.h>

int main() {
    char input1[255];
    char input2[255];
    
    // Assume input1 and input2 are read from a file
    
    // Convert input1 to uppercase
    for (int i = 0; input1[i] != '\0'; i++) {
        input1[i] = toupper(input1[i]);
    }
    
    // Convert input2 to uppercase
    for (int i = 0; input2[i] != '\0'; i++) {
        input2[i] = toupper(input2[i]);
    }
    
    printf("<%s> <%s>\n", input1, input2);
    
    return 0;
}
