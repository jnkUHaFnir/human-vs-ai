int main(void)
{
    char *l_boundRow;
    l_boundRow = NULL;
    int continueFlag = 1;  // Flag to control the loop based on user's choice.

    do {
        printf("Enter lower bound row: ");
        l_boundRow = getBoundary(l_boundRow);

        if (!checkStr(l_boundRow))
        {
            // If the input is not a valid integer, ask the user if they want to try again.
            continueFlag = doAgain();
        }
        else
        {
            // If it's a valid integer, exit the loop.
            continueFlag = 0;
        }
        
        // Free the previously allocated memory and set pointer to NULL
        // to ensure clean allocation in the next iteration or before exiting.
        free(l_boundRow);
        l_boundRow = NULL;
    } while (continueFlag);  // Loop while user wants to continue.

    return 0;
}
