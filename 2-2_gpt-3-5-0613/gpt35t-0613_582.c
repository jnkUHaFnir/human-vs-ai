/* Ask if do again */
int doAgain(void)
{
    char ans, c;

    do {
        printf("Do you want to try again?: ");
        ans = getchar(); // Use getchar instead of scanf

        switch (ans) 
        {   
            case 'y':
            case 'Y':
            case 'n':
            case 'N':
                // Flush the input buffer
                while ((c = getchar()) != '\n' && c != EOF) {}
                return (ans == 'y') || (ans == 'Y') ? 1 : 0;
                break;
            default:
                printf("Invalid answer!!! answer 'y' and 'Y' or 'n' and 'N' only\n");
                // Flush the input buffer
                while ((c = getchar()) != '\n' && c != EOF) {}
        }   
    } while (1);
}
