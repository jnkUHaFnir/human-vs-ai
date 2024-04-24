#include <stdio.h>
#include <string.h>

// Changed return type to void since we're modifying the string in place
void toUpper(char *str) {
    int i;
    // Fixed in the loop condition
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

int main() {
    char string[20]; // Be aware of buffer limitations

    printf("Enter any string:\n");
    // Added width specifier to prevent buffer overflow
    scanf("%19s", string);

    toUpper(string); // Modifies the string in-place

    printf("The string in upper case is: %s\n", string); // Directly print modified string

    return 0;
}
