#include <stdio.h>
#include <stdlib.h>

int new_strlen(char *tab) {
    int i;
    for (i = 0; tab[i] != '\0'; ++i);    
    return i;
}

int copyText(char from[], char to[], int max) {
    int len = new_strlen(from);
    
    if (len + 1 <= max) { // +1 for null-terminator
        for (int i = 0; from[i] != '\0'; i++) {
            to[i] = from[i];
        }
        to[len] = '\0'; // Ensure string is null-terminated
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char sentence[] = "C is \n a \n programming \t language";
    char sentence2[1000] = {0}; // It's a good practice to initialize arrays

    copyText(sentence, sentence2, sizeof(sentence2));
    printf("Show my array: %s \n", sentence2);

    return 0;
}
