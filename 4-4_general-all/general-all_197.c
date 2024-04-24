#include <stdio.h>

int main() {
    char x[50];
    
    // Read lines of text with scanf, break on ":" but include it
    while(scanf("%49[^:]:%*c", x) == 1) {
        printf("Read: %s\n", x);
    }
    
    return 0;
}
