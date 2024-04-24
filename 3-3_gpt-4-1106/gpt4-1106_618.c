char fileOutput[400]; // Buffer to hold each line from the file
char *inputPlate;
char *string;
int mileage;
Car *car;

while(fgets(fileOutput, sizeof(fileOutput), filePointer) != NULL) {
    // Use strtok to split the line into tokens
    inputPlate = strtok(fileOutput, " \n\r"); // Include newline and carriage return characters in delimiters
    if (inputPlate != NULL) {
        string = strtok(NULL, " \n\r"); // Proceed to the next token
        if (string != NULL) {
            mileage = atoi(string); // Convert from string to integer and store in mileage
        } else {
            // Handle case where no token is found after the first number
            fprintf(stderr, "Invalid input format - missing mileage value.\n");
            continue; // Skip to the next line
        }
    } else {
        // Handle case where no token is found on a line
        fprintf(stderr, "Invalid input format - missing plate number.\n");
        continue; // Skip to the next line
    }

    car = initializeCar(mileage, dateNULL, inputPlate); // You have not provided 'dateNULL' so make sure it is defined correctly
    avail->next = addList(avail->next, car, 0); // Make sure 'avail' is correctly initialized before this line
}

// Close the file if necessary
fclose(filePointer);
