    #include<stdio.h>
    #include<ctype.h>
    int main()
    {
        int number, sum = 0;
        int c; // char to read input
        // loop body is executed at least once
        do
        {
            printf("Enter a number: ");
            if(scanf("%d", &number)) {
                sum += number; // add if read was successful 
            }
            // buffer clean
            while ((c = getchar()) != '\n' && c != EOF);
        }
        while(number != 0);
        printf("Sum = %d",sum);
    }