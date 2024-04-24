double salary;
char input[100];
char *endptr;

printf("This program will compute your yearly and monthly withholding tax for you \n");

do {
    printf("How much is your total monthly salary? ");
    fgets(input, sizeof(input), stdin);
    
    // Convert input to a double
    salary = strtod(input, &endptr);

    // Check if input is a valid double and if endptr points to the newline character
    if (endptr == input || *endptr != '\n') {
        printf("\nInvalid input. Please enter a valid number.\n\n");
    } else {
        break; // Exit the loop if input is valid
    }
} while (1);

printf("Salary entered: %lf\n", salary);
// Proceed with the rest of your tax calculation logic
