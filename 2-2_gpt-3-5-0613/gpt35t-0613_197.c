#include <stdio.h>

int main() {
    char x[50];
    int c;
    
    while (scanf("%49[^:]", x) == 1) {
        // Read the character (':' in this case) separately
        scanf("%c", &c);
        
        // Print the input string along with the special character
        printf("%s%c\n", x, (char)c);
        
        // Clear the buffer until a newline character
        while ((c = getchar()) != '\n' && c != EOF)
            continue;
    }
    
    return 0;
}
