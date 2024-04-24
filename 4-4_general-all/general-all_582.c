int doAgain(void)
{
    char ans;
    int c;

    do {
        printf("Do you want to try again?: ");
        scanf(" %c", &ans);

        while ((c = getchar()) != '\n' && c != EOF); // Clear input buffer

        switch (ans) 
        {
            case 'y':
            case 'Y':
            case 'n':
            case 'N':
                return (ans == 'y') || (ans == 'Y') ? 1 : 0;
            default:
                printf("Invalid answer!!! answer 'y' and 'Y' or 'n' and 'N' only\n");
        }
    } while (1);
}
