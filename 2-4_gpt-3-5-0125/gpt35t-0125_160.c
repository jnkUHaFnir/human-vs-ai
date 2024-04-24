do
{
    printf("Do you want to try again? (Y/N): ");
    fflush(stdin);                              
    scanf(" %c", &repeat);
    repeat = toupper(repeat);
    if (repeat != 'Y' && repeat != 'N')         
        printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");
    else if (strlen(&repeat) > 1) // Check if input is more than 1 character
        printf("Invalid input. Please enter a single character.\n\n")
} while (repeat != 'N' && repeat != 'Y');
