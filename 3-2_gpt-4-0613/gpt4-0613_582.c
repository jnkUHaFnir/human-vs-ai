int main(void)
{
    char *l_boundRow;
    l_boundRow = NULL;
    
    do {
        printf("Enter lower bound row: ");
        l_boundRow  = getBoundary(l_boundRow);

        if (!checkStr(l_boundRow)) //checks if the user input is valid
        {
            if(doAgain())  //if input is invalid, the program asks user if they want to try again
                continue;
            else
                break;
        } 
        else
            break;

    }while (1);

    free(l_boundRow);
    return 0;
}
