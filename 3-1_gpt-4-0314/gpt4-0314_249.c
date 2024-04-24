int doAgain(void)
{
    char ans, c;

    do {
        printf("Do you want to try again?: ");

        // Read user input using getchar()
        ans = getchar();
        while((c = getchar()) != '\n' && c != EOF); // flush input stream

        switch (ans)
        {
            case 'y':
            case 'Y':
            case 'n':
            case 'N':
                return (ans == 'y') || (ans == 'Y') ? 1 : 0;
                break;
            default:
                printf("Invalid answer!!! answer 'y' and 'Y' or 'n' and 'N' only\n");
        }
    } while (1);
}
