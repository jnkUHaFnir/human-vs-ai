char answer;
while (1)
{
    printf("\n\nWould you like to run the program again? Type y or n. Then, hit Enter.");
    scanf(" %c", &answer);

    if (answer == 'y')
    {
        main();
    }
    else if (answer == 'n')
    {
        break;
    }
    else
    {
        printf("\nERROR: Invalid input was provided. Your answer must be either y or n. Hit Enter to continue.");
        while ((getchar()) != '\n');
    }
}
