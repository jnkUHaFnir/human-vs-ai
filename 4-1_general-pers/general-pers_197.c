#include <stdio.h>

int main() {
    char x[50];
    
    // Loop through input until the chosen character (in this case, ':') is encountered
    while(scanf("%49[^:\n]%c", x, &x[strlen(x)]) == 2) {
        // Print or process the input captured before the chosen character
        printf("Read: %s\n", x);
        // Break the loop if the chosen character is encountered
        if (x[strlen(x)-1] == ':') {
            break;
        }
    }
    
    return 0;
}
