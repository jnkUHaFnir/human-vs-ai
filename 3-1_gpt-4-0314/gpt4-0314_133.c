#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 100

int main()
{
    int number, sum = 0;
    char buffer[BUFFER_SIZE];

    // loop body is executed at least once
    do
    {
        printf("Enter a number: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if (buffer[strlen(buffer) - 1] != '\n') {
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // to clear the input buffer
        }
        buffer[strcspn(buffer, "\n")] = 0; // remove trailing newline
        int result = sscanf(buffer, "%d", &number);
        
        if (result == 1) {
            sum += number;
        } else {
            printf("Invalid input. Please enter a number.\n");
            number = 1; // to keep loop going
        }
    }
    while(number != 0);

    printf("Sum = %d", sum);
}
