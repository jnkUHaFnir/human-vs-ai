    #include <stdio.h>
    #include <string.h>
    
    int main(void)
    {
        char input[100];
        char reverse[100];
    
        int numLen = 0;
    
        printf("Enter a number\n");
        fgets(input, 100, stdin);
        printf("The number is: %s\n", input);
        input[strcspn(input,"\n")]='\0'; // getting the length of the 
                                         // string without `\n` 
                                         // and overwriting with `\0`
        numLen = strlen(input) ;  // now you don't need to put the -1
        printf("Length of string is: %d\n", numLen);
    
        for (int i = 0; i < numLen; i++)
        {
            ....