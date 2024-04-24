char answer[2];
answer[0] = 'a';
answer[1] = '\0';

while (strcmp(answer, "y") != 0 && strcmp(answer, "n") != 0)
{
    printf ("\n\nWould you like to run the program again? Type y or n. Then, hit Enter.");
    scanf(" %c", &answer[0]);

    if (strcmp(answer, "y") == 0)
    {
        main();
    }
    else if (strcmp(answer, "n") != 0)
    {
        printf ("\nERROR: Invalid input was provided. Your answer must be either y or n. Hit Enter to continue.");
        getchar();  // consume newline character
        while ((getchar()) != '\n');  // consume any remaining characters in the input buffer
    }
}
