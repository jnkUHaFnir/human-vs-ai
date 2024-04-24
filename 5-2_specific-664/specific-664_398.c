#include <stdio.h>

int main() {
    int counter[5] = {0};
    int c, i;

    printf("Please enter a string terminated by ENTER key:\n");

    while ((c = getchar()) != '\n') {
        // Convert input character to lowercase
        c = tolower(c);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            for (i = 0; i < 5; i++) {
                if (c == 'a' + i) {
                    counter[i]++;
                }
            }
        }
    }

    for (i = 0; i < 5; i++) {
        printf("counter[%d] = %d\n", i, counter[i]);
    }

    int total_vowels = counter[0] + counter[1] + counter[2] + counter[3] + counter[4];
    printf("\nTotal number of Vowels= %d\n", total_vowels);

    return 0;
}
