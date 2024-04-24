#include <stdio.h>

int main(void)
{
    unsigned char value;

    /* To read the numbers between 0 to 255 */
    unsigned int input;
    printf("Please enter a number between 0 and 255 \n");
    
    if (scanf("%u", &input) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    
    if (input < 0 || input > 255) {
        printf("Input is out of range\n");
        return 1;
    }
    
    value = (unsigned char)input;
    
    printf("The value is %u \n", value);
    
    return 0;
}
