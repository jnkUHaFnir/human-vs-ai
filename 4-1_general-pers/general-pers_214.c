#include<stdio.h>

void main()
{
    char* ptr, str[30];
    int size = 0;

    puts("Enter the string:");
    gets(str);

    for(ptr = str; *ptr != '\0'; ptr++)
    {
        if (*ptr != ' ')  // Skip counting spaces
        {
            size++;
        }
    }

    printf("Size of string without spaces is = %d\n", size);
    getchar();
}
