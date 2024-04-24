scanf("%s", word); // Correct
printf("%c", word[i]); // Correct
#include <stdio.h>
#include <string.h>

int main() {
    char word[20];
    int i, len;

    printf("Enter word: ");
    scanf("%s", word); // No need for & here

    len = strlen(word);

    printf("String reversed: ");
    for (i = len - 1; i >= 0; i--) {
        printf("%c", word[i]); // Use %c for characters
    }

    printf("\n"); // To add a newline at the end of the output

    return 0;
}
