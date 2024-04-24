int main(void)
{

    char *l_boundRow;
    l_boundRow = NULL;

    int tryAgain = 1; // Initialize tryAgain variable

    do {
        printf("Enter lower bound row: ");
        l_boundRow  = getBoundary(l_boundRow);

        if (!checkStr(l_boundRow))
        {
            if (doAgain())
            {
                tryAgain = 1;
            }
            else
            {
                tryAgain = 0;
                break;
            }
        }
        else
        {
            tryAgain = 0;
            break;
        }
    } while (tryAgain);

    free(l_boundRow);
    return 0;
}
