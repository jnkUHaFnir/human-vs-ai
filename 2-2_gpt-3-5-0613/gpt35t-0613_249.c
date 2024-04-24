int doAgain(void)
{
    char ans, c;

    do {
        printf("Do you want to try again?: ");
        ans = getchar();

        switch (ans) {   
            case 'y':
            case 'Y':
            case 'n':
            case 'N':
                // flush input stream
                while ((c = getchar()) != '\n' && c != EOF);

                return (ans == 'y') || (ans == 'Y') ? 1 : 0;
                break;
            default:
                printf("Invalid answer!!! Answer 'y' and 'Y' or 'n' and 'N' only\n");
                // flush input stream
                while ((c = getchar()) != '\n' && c != EOF);
                break;
        }   
    } while (1);
}
