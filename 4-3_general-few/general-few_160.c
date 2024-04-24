int c;

do {
    printf("Do you want to try again? (Y/N): ");
    
    // Clear the input buffer
    while ((c = getchar()) != '\n' && c != EOF);
    
    scanf("%c", &repeat);
    repeat = toupper(repeat);

    if (repeat != 'Y' && repeat != 'N') {
        printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");
    }

} while (repeat != 'N' && repeat != 'Y');
