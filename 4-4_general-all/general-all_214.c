#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[30];
    int size = 0;
    
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\r') {
            size++;
        }
    }

    printf("Number of non-space characters in the string: %d\n", size);

    return 0;
}
