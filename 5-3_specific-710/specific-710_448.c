#include <stdio.h>

int main(void)
{
    unsigned char value;

    /* To read the numbers between 0 to 255 */
    printf("Please enter a number between 0 and 255 \n");
    scanf("%hhu", &value);
    printf("The value is %u \n", value);

    return 0;
}
