int validate(int low, int high) {
    int selection;

    do {
        scanf("%d", &selection); // Use & to store input in the variable's address
        if (selection < low || selection > high) // Use arguments low and high
            printf("Invalid Input, try again: ");
    } while (selection < low || selection > high); // Use arguments low and high

    return selection;
}
// ...
int low = 1;
int high = 3;
int Valid_Selection;

// Display main menu and prompt for user selection...

// Validate user input using the validate function
Valid_Selection = validate(low, high); // pass the variables, not types

// Based on the Valid_Selection, you would then decide what to do
// ...

int selection;
int result;

do {
    result = scanf("%d", &selection);
    if (result != 1) { // Check if scanf successfully read an integer
        printf("Invalid input, please enter a number: ");
        while (getchar() != '\n'); // Consume non-integer input
        continue; // Skip to the next iteration of the loop
    }

    if (selection < low || selection > high) 
        printf("Invalid Input, try again: ");

} while (selection < low || selection > high);

return selection;
