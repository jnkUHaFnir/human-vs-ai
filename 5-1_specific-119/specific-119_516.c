#include <stdio.h>

int main(int argc, const char * argv[]) {
    int age;

    do {
        printf("How old are you?\n");
        if (scanf("%d", &age) != 1) {
            printf("Error, invalid input. Please enter a valid age.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            if (age == 3267) {
                printf("Cool.\n");
                break;
            } else {
                printf("Error, retry:\n");
            }
        }
    } while (age != 3267);

    return 0;
}
