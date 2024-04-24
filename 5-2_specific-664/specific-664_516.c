#include <stdio.h>
#include <stdlib.h>

int main() {
    int age;
    int result;

    do {
        printf("How old are you?\n");
        result = scanf("%d", &age);
        
        if (result != 1) {
            printf("Error, retry: \n");
            // Clear input buffer
            while (fgetc(stdin) != '\n');
        } else {
            printf("Cool.");
            break;
        }
    } while (1);

    return 0;
}
