int check;
char name[100]; // ensure name is large enough to hold expected input
do {
    check = 0;
    printf("Please enter a valid name: ");
    scanf("%99s", name); // %99s to prevent buffer overflow
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha((unsigned char)name[i])) { // cast to unsigned char for safety
            printf("Invalid character. Please enter a valid name.\n");
            check = 1;
            break;
        }
    }
} while (check == 1);
// Capitalize first letter and make the rest lowercase
name[0] = toupper((unsigned char)name[0]);
for (int i = 1; name[i] != '\0'; i++) {
    if (name[i - 1] == ' ') {
        name[i] = toupper((unsigned char)name[i]);
    } else {
        name[i] = tolower((unsigned char)name[i]);
    }
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>
