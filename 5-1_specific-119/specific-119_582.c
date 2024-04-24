/* Ask if try again */
int doAgain(void)
{
    char ans, c;

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
                printf("Invalid answer!!! Answer 'y' and 'Y' or 'n' and 'N' only\n");
        }   
    } while (1);
}
