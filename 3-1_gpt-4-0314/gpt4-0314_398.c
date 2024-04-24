#include <stdio.h>

int main() {
    int counter[5];
    int c, i;

    for(i = 0; i < 5; i++) {
        counter[i] = 0;
    }

    printf("Please enter a string terminated by ENTER key:\n");

    while((c = getchar()) != '\n') {
        for(i = 0; i < 5; i++) {
            if(c == 'a' + i || c == 'A' + i) {
                counter[i]++;
            }
        }
    }

    int totalVowels = 0;
    for(i = 0; i < 5; i++) {
        printf("counter[%d] = %d\n", i, counter[i]);
        totalVowels += counter[i];
    }

    printf("Total number of vowels = %d\n", totalVowels);

    return 0;
}
