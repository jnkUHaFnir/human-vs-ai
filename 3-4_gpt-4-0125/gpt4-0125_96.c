#include <stdio.h>
#include <string.h>

int main() {
    char word[20];
    int i, len;

    printf("Enter word: ");
    scanf("%s", word); // Fixed the use of &

    len = strlen(word);

    printf("String reversed: ");
    for (i = len - 1; i >= 0; i--) {
        printf("%c", word[i]); // Corrected the format specifier to %c
    }
    printf("\n"); // Added to make output cleaner

    return 0;
}
