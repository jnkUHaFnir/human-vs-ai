#include <stdio.h>

int main() {
    char x[50];

    // Read until ':' is encountered, including ':'
    while(scanf("%49[^:]", x) == 1) {
        char ch;
        if(scanf("%c", &ch) == 1) {
            if(ch == ':') {
                // Include ':' in the output
                printf("%s%c\n", x, ch);
            } else {
                // Append the character after ':' and include it
                printf("%s%c\n", x, ch);
                break;
            }
        } else {
            // If end of input is reached
            printf("%s\n", x);
            break;
        }
    }

    return 0;
}
