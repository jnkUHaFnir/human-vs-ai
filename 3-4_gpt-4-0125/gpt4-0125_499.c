#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Globals
int secret_nr;
int guess;
int upper_bound = 100;
int lower_bound = 1;
int total_guesses = 1;

void check_input(void) {
    if (guess < lower_bound || guess > upper_bound) {
        printf("Invalid input! Your guess must be between %d and %d\n", lower_bound, upper_bound);
    }
    else if (guess < secret_nr) {
        printf("Higher\n");
        total_guesses++;
    }
    else if (guess > secret_nr) {
        printf("Lower\n");
        total_guesses++;
    }
    else if (guess == secret_nr) {
        printf("Correct! You guessed the number after guessing %d times!\n", total_guesses);
    }
}

// Function to clear the input buffer
void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    secret_nr = (rand() % (upper_bound - lower_bound + 1)) + lower_bound; // This ensures the secret number is within bounds

    printf("Guess the number between %d and %d:\n", lower_bound, upper_bound);
    do {
        int result = scanf("%d", &guess);
        if (result == 1) {
            check_input();
        }
        else {
            printf("Invalid input! Only integer values are allowed!\n");
            clear_input_buffer(); // Clear the input buffer if input is invalid
        }
    } while (guess != secret_nr);

    return 0;
}
