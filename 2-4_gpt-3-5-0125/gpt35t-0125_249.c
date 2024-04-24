int main(void)
{
    char *l_boundRow;
    l_boundRow = NULL;
    int isValidInput;

    do {
        printf("Enter lower bound row: ");
        l_boundRow = getBoundary(l_boundRow);

        isValidInput = checkStr(l_boundRow); // Check if the input is valid
        if (!isValidInput) {
            if (doAgain()) {
                continue; // If user wants to try again, continue the loop
            } else {
                break; // If user doesn't want to try again, exit the loop
            }
        } else {
            break; // If input is valid, exit the loop
        }
    } while (1);

    free(l_boundRow);
    return 0;
}
