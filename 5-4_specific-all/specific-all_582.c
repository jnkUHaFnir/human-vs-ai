int main(void)
{
    char *l_boundRow = NULL;
    int tryAgain; // Variable to control loop continuation

    do {
        printf("Enter lower bound row: ");
        l_boundRow = getBoundary(l_boundRow);

        if (!checkStr(l_boundRow)) {
            if (!doAgain()) {
                tryAgain = 0;
            }
        } else {
            tryAgain = 0;
        }
    } while (tryAgain);

    free(l_boundRow);
    return 0;
}
