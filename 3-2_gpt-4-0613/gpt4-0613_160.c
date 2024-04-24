char input[50];
do
{
    printf("Do you want to try again? (Y/N): ");
    fflush(stdin);                             
    fgets(input, 50, stdin);
    // remove newline character obtained from fgets 
    char* pos;
    if ((pos = strchr(input, '\n')) != NULL) {
      *pos = '\0';
    }
    // remove leading and trailing whitespaces and convert the first character to uppercase
    char repeat = toupper(input[0]);
    if (strlen(input) != 1 || (repeat != 'Y' && repeat != 'N')) {       
        printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");
    }
} while (strlen(input) != 1 || (toupper(input[0]) != 'Y' && toupper(input[0]) != 'N')); 

