#include <stdio.h>
int main() {
    int counter[5] = {0};
    int c, i;

    printf("Please enter a string terminated by ENTER key:\n");
    while ((c = getchar()) != '\n') {
        // Convert c to lowercase
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

    int totalVowels = 0;
    for (i = 0; i < 5; i++) {
        totalVowels += counter[i];
    }
    printf("Total number of Vowels = %d\n", totalVowels);

    return 0;
}
