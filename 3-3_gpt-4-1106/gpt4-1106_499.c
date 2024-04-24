#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//globals
int secret_nr;
int guess;
int upper_bound = 100;
int lower_bound = 1;
int total_guesses = 1;

void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); // Discard characters until a newline or EOF
}

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

int main(int argc, char* argv[]) {
    srand(time(NULL));
    secret_nr = rand() % (upper_bound - lower_bound + 1) + lower_bound; // ensure secret_nr is in the right range

    printf("Guess the number between %d and %d:\n", lower_bound, upper_bound);
    while (1) {
        int result = scanf("%d", &guess);
        if (result == 1) { // An integer was successfully read
            check_input();
            if (guess == secret_nr) {
                break;
            }
        } else {
            printf("Invalid input! Only integer values are allowed!\n");
            clear_input_buffer(); // Clear the invalid input so it doesn't cause an infinite loop
        }
    }

    return 0;
}
