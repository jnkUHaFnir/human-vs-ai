#include <stdio.h>

int main() {
    char x[50];
    while(scanf("%49[^:]:%c", x, &x[49]) == 2) {
        printf("Read: %s%c\n", x, x[49]);
    }

    return 0;
}
