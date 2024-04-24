if (!checkStr(l_boundRow) && doAgain())
do {
    printf("Enter lower bound row: ");
    l_boundRow = getBoundary(l_boundRow);

    if (!checkStr(l_boundRow)) { // If the string is invalid...
        if (!doAgain()) { // If the user does not want to continue...
            free(l_boundRow);
            return 0; // Exit the program if the user doesn't want to continue.
        }
    } else {
        break; // The string is valid, so we exit the loop.
    }
} while (1);
// Your includes here...

// getBoundary function...

// checkStr function...

// doAgain function...

// Main
int main(void)
{
    char *l_boundRow = NULL;

    do {
        printf("Enter the lower bound row: ");
        l_boundRow = getBoundary(l_boundRow);

        if (!checkStr(l_boundRow)) { // If the string is invalid...
            if (!doAgain()) { // If the user does not want to continue...
                free(l_boundRow);
                return 0; // Exit the program if the user doesn't want to continue.
            }
        } else {
            break; // The string is valid, so we exit the loop.
        }
    } while (1);

    // Assume your processing of l_boundRow happens here...

    free(l_boundRow);
    return 0;
}
