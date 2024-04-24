#include <stdio.h>
#include <stdlib.h>

int main() {
    int age;

    do {
        printf("How old are you?\n");
        if (scanf("%d", &age) != 1) {
            printf("Error, retry: \n");
            // Clear the input buffer
            while(getchar() != '\n');
        } else {
            printf("Cool.\n");
            break;
        }
    } while (1);

    return 0;
}
