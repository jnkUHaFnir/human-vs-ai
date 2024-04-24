#include <stdio.h>
#include <string.h>

int main() {
    char word[20];
    int i, len;
    
    printf("Enter word: ");
    scanf("%s", word);

    len = strlen(word);

    printf("String reversed: ");
    for (i = 0; i < len/2; i++) {
        char temp = word[i];
        word[i] = word[len-1-i];
        word[len-1-i] = temp;
    }
    printf("%s", word);
    return 0;
}
