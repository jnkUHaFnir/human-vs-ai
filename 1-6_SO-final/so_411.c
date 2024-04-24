    #include <stdio.h>
    #include <ctype.h>
    void shift (char *my_string);//function declaration
    int main()
    {
    char inputstring[50];
    printf("Enter a string\n");
    shift(inputstring);
    }
    void shift (char *my_string) //function definition
    {
    int i =0;
    char ch;
    fgets(my_string, 50, stdin);
    while(my_string[i])
    {
        if(ch>='A' && ch<= 'Z') //when first char is uppercase
        {
            putchar (toupper(my_string[i]));
            i++;
        }
        else if (ch>='a' && ch <= 'z')//when first char is lowercase
        {
            putchar(tolower(my_string[i]));
            i++;
        }
    }
    return;
    }