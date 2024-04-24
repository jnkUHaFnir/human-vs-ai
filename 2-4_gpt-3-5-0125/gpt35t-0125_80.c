double salary;
int validInput = 0;

printf("This program will compute your yearly and monthly witholding tax for you \n");

do {
    printf("How much is your total monthly salary? ");

    // Clear the input buffer before reading input
    fflush(stdin);

    // Check if the input is a double value
    if (scanf("%lf", &salary) == 1) {
        validInput = 1;
    } else {
        printf("Invalid Input, please enter a valid number\n");
    }
} while (!validInput || salary < 0);

// Proceed with the rest of your program
