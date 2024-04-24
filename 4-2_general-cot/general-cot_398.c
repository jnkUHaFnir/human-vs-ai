#include <stdio.h>

int main() {
    int counter[5] = {0};
    int c, i;

    printf("Please enter a string terminated by ENTER key:\n");
    while ((c = getchar()) != '\n') {
        if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ||
            (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            for (i = 0; i < 5; i++) {
                char vowel = 'a' + i;
                if (c == vowel || c == vowel - 32) { // considering uppercase vowels
                    counter[i]++;
                }
            }
        }
    }

    for (i = 0; i < 5; i++) {
        printf("counter[%d] = %d\n", i, counter[i]);
    }

    // Calculate total number of vowels
    int total_vowels = 0;
    for (i = 0; i < 5; i++) {
        total_vowels += counter[i];
    }
    printf("Total number of Vowels= %d\n", total_vowels);

    return 0;
}
