int main(void)
{
    char *l_boundRow = NULL;

    do {
        printf("Enter lower bound row: ");
        l_boundRow = getBoundary(l_boundRow);

        if (!checkStr(l_boundRow)) {
            if (doAgain()) {
                free(l_boundRow);
                l_boundRow = NULL;
                continue;
            } else {
                break;
            }
        } else {
            break;
        }
    } while (1);

    free(l_boundRow);
    return 0;
}
