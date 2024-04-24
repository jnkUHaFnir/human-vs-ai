#include <stdio.h>
#include <string.h>

int main() {
    char word[20];
    int i, len;

    printf("Enter word: ");
    scanf("%19s", word); // Limit input size to prevent buffer overflow

    len = strlen(word);

    printf("String reversed: ");
    for (i = len-1; i >= 0; i--){
        printf("%c", word[i]); // Print a single character using %c, not %s
    }

    return 0;
}
