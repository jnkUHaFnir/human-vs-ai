#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        printf("correct! You guessed the number after guessing %d times!\n", total_guesses);
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    secret_nr = (rand() % upper_bound) + 1;

    printf("Guess the number between %d and %d:\n", lower_bound, upper_bound);

    while (1) {
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Only integer values are allowed!\n");
            // Clear input buffer
            while(getchar() != '\n');
        }
        else {
            check_input();
            if (guess == secret_nr) {
                break;
            }
        }
    }

    return 0;
}
