int validate(int low, int high) {
    int selection;

    do {
        scanf("%d", &selection); // Notice the usage of & before variable name.
        if (selection < low || selection > high) // Use low and high variables
            printf("Invalid Input, try again: ");
    // Correct the while condition to use logical operators correctly
    } while (selection < low || selection > high);

    return selection;
}
printf("Selection: ");
	fflush(stdout);  // Ensure "Selection: " is printed before scanf blocks for input

	// Correct function call
	Valid_Selection = validate(low, high);

	// Based on Valid_Selection, you can then proceed to either start a new game,
	// load a game, or exit. This logic is currently missing and should be implemented
	// based on your game's requirements.
while ((getchar()) != '\n'); // Consume up to the newline character
