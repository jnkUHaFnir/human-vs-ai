#include <stdio.h>
#include <string.h>

int main() {
    char answer[10];
    int guess;
    int diceRoll4 = 0;

    printf("Would you like to guess your next dice? Y/N \n");
    scanf("%s", answer);

    if (strcmp(answer, "yes") == 0) {
        printf("What is your guess?\n");
        printf("Please key in your number \n");
        scanf("%d", &guess);

        if (guess > diceRoll4) {
            printf("You got it wrong, too high!\n");
        }
        else if (guess < diceRoll4) {
            printf("You got it wrong, too low!\n");
        }
        else {
            printf("You got it right\n");
        }
    }
    else {
        printf("Thanks for playing\n");
    }

    return 0;
}
