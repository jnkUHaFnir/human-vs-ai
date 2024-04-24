#include <stdio.h>
#include <string.h>

int main() {
    char word[20];
    int i, len;

    printf("Enter word: ");
    scanf("%s", word);

    len = strlen(word);

    printf("String reversed: "); 
    for (i = len - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
    
    return 0;
}
