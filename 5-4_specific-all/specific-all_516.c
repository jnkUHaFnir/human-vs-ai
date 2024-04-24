#include <stdio.h>
#include <stdlib.h>

int main() {
    int age;
    char input[100];

    do {
        printf("How old are you?\n");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            exit(1);
        }

        if (sscanf(input, "%d", &age) != 1) {
            printf("Error, retry: Input must be a valid integer.\n");
        } else {
            if (age == 32767) {
                printf("Error, retry: Can't use 32767 as age.\n");
            } else {
                printf("Cool.\n");
                break;
            }
        }
    } while(1);

    return 0;
}
