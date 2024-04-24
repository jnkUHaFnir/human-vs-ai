int main(void)
{
    char *l_boundRow;
    l_boundRow = NULL;

    int isValidInput = 0;

    do {
        printf("Enter lower bound row: ");
        l_boundRow = getBoundary(l_boundRow);

        if (checkStr(l_boundRow))
        {
            isValidInput = 1;
        }
        else
        {
            printf("Invalid integer format!!");
        }

        // Prompt for user input only if the input is invalid
        if (!isValidInput)
        {
            free(l_boundRow); // Free the memory before getting new input
            if (!doAgain())
            {
                break; // If user does not want to try again, exit the loop
            }
            else
            {
                l_boundRow = NULL; // Reset l_boundRow for new input
            }
        }

    } while (!isValidInput);

    free(l_boundRow);
    return 0;
}
