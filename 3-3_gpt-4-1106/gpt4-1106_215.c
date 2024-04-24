#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char name[100]; // Assuming name length won't exceed 99 characters plus null terminator
    int check;
    int i;
    do {
        printf("Enter a valid name: ");
        scanf("%99s", name); // Limit input to 99 characters to prevent buffer overflow
        check = 0;
        for (i = 0; i < strlen(name); i++) {
            if (!isalpha((unsigned char)name[i])) { // Cast to unsigned char to avoid undefined behavior
                printf("Invalid character. Please enter a valid name.\n");
                check = 1;
                break;
            }
        }
    } while (check == 1);

    // All to lowercase except the first letter and after every space
    for (i = 1; i < strlen(name); i++) {
        name[i] = tolower((unsigned char)name[i]);
    }
    name[0] = toupper((unsigned char)name[0]);
    for (i = 1; name[i] != '\0'; i++) {
        if (name[i - 1] == ' ') {
            name[i] = toupper((unsigned char)name[i]);
        }
    }

    printf("Formatted Name: %s\n", name);

    return 0;
}
