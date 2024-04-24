#include <stdio.h>

int main() {
    char x[50];

    // Read lines of text until ':' is encountered
    while(scanf("%49[^:]:%c", x, x + 49) == 2) {
        printf("Read: %s\n", x);
    }

    return 0;
}
