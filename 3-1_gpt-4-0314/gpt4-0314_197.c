#include <stdio.h>

int main() {
    char x[50];
    char ch;
    
    while (scanf("%49[^:\n]%c", x, &ch) == 2) {
        if (ch == ':') {
            printf("Read line: %s and the special character: %c\n", x, ch);
        } else {
            printf("Read line without special character: %s\n", x);
            break;
        }
    }
    
    return 0;
}
