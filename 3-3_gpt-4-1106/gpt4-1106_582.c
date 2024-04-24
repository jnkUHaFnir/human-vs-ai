int main(void)
{
    char *l_boundRow;
    l_boundRow = NULL;

    int validInput;

    do {
        printf("Enter lower bound row: ");
        l_boundRow = getBoundary(l_boundRow);

        // Check if the input string is valid.
        validInput = checkStr(l_boundRow);

        if (!validInput) { // If the input is not valid, ask to try again.
            if (doAgain()) {
                free(l_boundRow); // Free the allocated memory.
                l_boundRow = NULL; // Reset the pointer to avoid dangling reference.
                continue; // Re-enter the loop to ask for input again.
            } else {
                break; // Exit the loop if the user does not want to try again.
            }
        } else {
            break; // Input is valid, break out of the loop.
        }
    } while (1);

    free(l_boundRow);
    return 0;
}
char* getBoundary(void){
    int i = 0;
    char c;
    char *str = NULL;
    str = (char*) malloc(sizeof(char));

    // Loop reads characters until a newline is encountered.
    while((c = getchar()) != '\n' && c != EOF) {
        str = (char *) realloc(str, i + 2); // Allocate space for the current chars plus the null terminator.
        str[i++] = c;
    }

    str[i] = '\0'; // Ensure the string is null-terminated.
    return str;
}
