#include <stdio.h>
#include <ctype.h>  // For tolower() function

int main() {
    int counter[5] = {0};  // This initializes all elements to 0
    int c, totalVowels = 0;

    printf("Please enter a string terminated by ENTER key:\n");
    while ((c = getchar()) != '\n') {
        c = tolower(c);  // Convert to lower case for easier handling
        if (c == 'a') {
            counter[0]++;
        } else if (c == 'e') {
            counter[1]++;
        } else if (c == 'i') {
            counter[2]++;
        } else if (c == 'o') {
            counter[3]++;
        } else if (c == 'u') {
            counter[4]++;
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("counter[%d] = %d\n", i, counter[i]);
        totalVowels += counter[i];  // Calculate the total number of vowels
    }

    printf("Total number of Vowels= %d\n", totalVowels);

    return 0;
}
