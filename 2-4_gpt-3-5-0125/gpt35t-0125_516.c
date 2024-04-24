#include <stdio.h>

int main(int argc, const char * argv[]) {
    int age;

    while(1) {
        printf("How old are you?\n");
        if (scanf("%d", &age) != 1) {
            printf("Error, please enter a valid age.\n");
            // Clear the input buffer
            while(getchar() != '\n');
        } else {
            printf("Cool.\n");
            break;
        }
    }

    return 0;
}
