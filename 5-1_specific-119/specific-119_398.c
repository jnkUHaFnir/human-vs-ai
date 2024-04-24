#include <stdio.h>
#include <ctype.h>

int main() {
    int counter[5] = {0};
    int c;
    printf("Please enter a string terminated by ENTER key: \n");

    while ((c = getchar()) != '\n') {
        c = tolower(c); // Convert to lowercase for comparison

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            for (int i = 0; i < 5; i++) {
                if (c == 'a' + i) {
                    counter[i]++;
                }
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("counter[%d] = %d\n", i, counter[i]);
    }

    int totalVowels = counter[0] + counter[1] + counter[2] + counter[3] + counter[4];
    printf("Total number of Vowels = %d\n", totalVowels);

    return 0;
}
