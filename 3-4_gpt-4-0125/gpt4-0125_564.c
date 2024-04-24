#include <stdio.h>

int main()
{
    char name[101]; // Allocate space for 100 characters + the null terminator
    printf("Your name: \n");

    // Read input using fgets. stdin is the standard input stream.
    fgets(name, sizeof(name), stdin);

    // fgets includes the newline character in the buffer. To remove it:
    name[strcspn(name, "\n")] = '\0';

    printf("Name: %s\n", name);

    return 0;
}
