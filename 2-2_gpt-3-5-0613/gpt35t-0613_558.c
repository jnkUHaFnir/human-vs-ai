int menu() {
    int choice;
    printf("1)Lab 5 ( Repetitions ).\n2)Lab 10 ( Passing 1D-Arrays to functions ).\n3)GPA Calculation.\n4)EXIT.\n\nEnter your choice: ");

    // Use a loop to keep asking for input until a valid integer is entered
    while (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a valid integer choice: ");
        fseek(stdin, 0, SEEK_END); // Clear the input buffer
    }
  
    return choice;
}
