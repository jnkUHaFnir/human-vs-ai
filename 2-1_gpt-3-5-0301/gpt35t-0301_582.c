/* Ask if do again */
int doAgain(void)
{
    char ans, c;

    do {
        printf("Do you want to try again? (y/n): ");
        scanf(" %c", &ans);

        switch (ans) 
        {   
            case 'y':
            case 'Y':
                return 1;
            case 'n':
            case 'N':
                return 0;
            default:
                printf("Invalid answer!!! answer 'y' and 'Y' or 'n' and 'N' only\n");
                do { /* flush input stream */
                    c = getchar();
                }while (c != '\n'); 
        }   
    }while (1);
}

/* Main */
int main(void)
{
    char *l_boundRow = NULL;

    do {
        printf("Enter lower bound row: ");
        l_boundRow = getBoundary(l_boundRow);

        if (checkStr(l_boundRow)) {
            break;
        }

    } while (doAgain());

    free(l_boundRow);
    return 0;
}
