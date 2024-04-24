#include <stdio.h>

int main() {
    int age;

    do {
        printf("How old are you?\n");
        if (scanf("%d", &age) != 1) {
            printf("Error, retry: \n");
            while (fgetc(stdin) != '\n'); // clear input buffer
        } else {
            if (age == 32767) {
                printf("Error, retry: \n");
            } else {
                printf("Cool.");
                break;
            }
        }
    } while (1);

    return 0;
}
