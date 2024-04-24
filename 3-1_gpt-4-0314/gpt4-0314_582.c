int main(void)
{
    char *l_boundRow;
    l_boundRow = NULL;
    int valid_input = 0;

    do {
        printf("Enter lower bound row: ");
        l_boundRow  = getBoundary(l_boundRow);

        if (!checkStr(l_boundRow)) {
            if (doAgain()) {
                valid_input = -1; // keep asking for input
            } else {
                valid_input = 0;
                break; // if the user does not wish to continue, break the loop
            }
        } else {
            valid_input = 1;
            break; // if the string is valid, stop loop
        }
    } while (valid_input != 1);

    if (valid_input == 1) {
        printf("The valid input is: %s\n", l_boundRow);
    }
    free(l_boundRow);

    return 0;
}
