#include <stdio.h>
#include <string.h>

void uppercase(char source[]) {
    for (int i = 0; source[i] != '\0'; ++i)
        if (source[i] >= 'a' && source[i] <= 'z')
            source[i] = source[i] - 'a' + 'A';
    // We do not need the else branch because it does not do anything
}

int main() {
    char str[] = "cold"; // Modifiable array containing the string "cold"
    uppercase(str);
    printf("%s\n", str); // This will print the modified string, which should be "COLD"
    return 0;
}
