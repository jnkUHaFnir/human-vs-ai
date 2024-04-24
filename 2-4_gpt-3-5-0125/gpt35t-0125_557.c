int menu() {
    int choice;
    int scanfResult;

    printf("1)Lab 5 ( Repetetitions ).\n2)Lab 10 ( Passing 1D-Arrays to functions ).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");
    
    // Check if the input is an integer
    scanfResult = scanf("%d", &choice);
    
    if (scanfResult != 1) {
        // Clear input buffer in case of non-integer input
        while((getchar()) != '\n');
        choice = -1; // Assign an invalid choice
    }

    return choice;
}
