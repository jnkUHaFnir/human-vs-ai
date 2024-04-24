#include <stdio.h>

int main(void) {
    unsigned char value;

    /* To read numbers between 0 to 255 */
    printf("Please enter a number between 0 and 255 \n");
    if (scanf("%hhu", &value) == 1) {
        printf("The value is %u \n", value);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}
