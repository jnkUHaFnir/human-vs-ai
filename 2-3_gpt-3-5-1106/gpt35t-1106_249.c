int main(void)
{
    char *l_boundRow;
    l_boundRow = NULL;
    int tryAgain;

    do {
        printf("Enter lower bound row: ");
        l_boundRow = getBoundary(l_boundRow);

        if (!checkStr(l_boundRow))
        {
            tryAgain = doAgain();
            if (tryAgain)
            {
                free(l_boundRow);
                l_boundRow = NULL; // Reset the input
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    } while (1);

    free(l_boundRow);
    return 0;
}
