#include <stdio.h>

int menu() {            // prints the main menu of labs///
    int choice;
    int inputResult;
    do {
        printf("1)Lab 5 ( Repetetitions ).\n2)Lab 10 ( Passing 1D-Arrays to functions ).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");
        inputResult = scanf("%d", &choice);
        
        if (inputResult != 1) {
            printf("Invalid input. Please enter a number.\n");
            scanf("%*s"); // Clear the input buffer
        }
    } while (inputResult != 1);
    
    return choice;
}
