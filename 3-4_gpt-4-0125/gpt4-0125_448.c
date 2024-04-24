#include<stdio.h>

int main(void)
{
    unsigned char value;
    unsigned int temp;

    /* To read the numbers between 0 to 255 */
    printf("Please enter a number between 0 and 255 \n");
    
    // Use %u to read into an unsigned int
    if (scanf("%u", &temp) == 1) {
        if (temp <= 255) {
            value = (unsigned char)temp; // Cast to unsigned char after range check
            printf("The value is %u \n", value);
        } else {
            printf("The entered value is out of range.\n");
        }
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}
