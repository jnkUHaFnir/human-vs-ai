#include <stdio.h>

int main() { // Make sure that main returns an int.
    // Declare an array of 5 integer counters.
    int counter[5];
    int c, i;
    int totalVowels = 0; // To keep track of the total number of vowels.

    // Initialize each member of the counter array to 0.
    for(i = 0; i < 5; i++)
        counter[i] = 0;

    // Prompt the user to input a string.
    printf("Please enter a string terminated by ENTER key:\n");

    // Read each character until a newline (ENTER) is encountered.
    while((c = getchar()) != '\n') {
        c = tolower(c); // Convert character to lowercase for easy comparison.
        if(c == 'a') {
            counter[0]++;
            totalVowels++;
        } else if(c == 'e') {
            counter[1]++;
            totalVowels++;
        } else if(c == 'i') {
            counter[2]++;
            totalVowels++;
        } else if(c == 'o') {
            counter[3]++;
            totalVowels++;
        } else if(c == 'u') {
            counter[4]++;
            totalVowels++;
        }
    }

    // Print out the counts of each vowel.
    for(i = 0; i < 5; i++)
        printf("counter[%d] = %d\n", i, counter[i]);

    // Print the total number of vowels.
    printf("Total number of Vowels = %d\n", totalVowels);

    return 0; // Return 0 to indicate successful completion.
}
