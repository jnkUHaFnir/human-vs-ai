#include <stdio.h>

int main() {
    int counter[5] = {0};
    int c, i;

    printf("Please enter a string terminated by ENTER key:\n");

    while ((c = getchar()) != '\n') {
        if((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') || (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            for(i = 0; i < 5; i++) {
                if(c == 'a' + i || c == 'A' + i) {
                    counter[i]++;
                }
            }
        }
    }

    for(i = 0; i < 5; i++) {
        printf("counter[%d] = %d\n", i, counter[i]);
    }

    int totalVowels = counter[0] + counter[1] + counter[2] + counter[3] + counter[4];
    printf("Total number of Vowels = %d\n", totalVowels);

    return 0;
}
