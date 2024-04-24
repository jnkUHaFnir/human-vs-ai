#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assuming the structure and functions like initializeCar and addList are defined somewhere
// Just for the sake of this example, I will comment out actual car-related operations

// struct Car {
//     // Car properties
// };

// Car* initializeCar(int mileage, Date date, char* inputPlate) {
//     // Initialize car
//     // Return pointer to the newly created car
// }

// List* addList(List* list, Car* car, int position) {
//     // Add car to the list at the specified position
//     // Return the head of the list
// }

#define MAX_LINE_LENGTH 400

int main() {
    FILE *filePointer = fopen("yourfile.txt", "r");
    if (filePointer == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char fileOutput[MAX_LINE_LENGTH]; // Buffer to store line read from the file
    char *inputPlate, *string;
    int mileage;

    while (fgets(fileOutput, MAX_LINE_LENGTH, filePointer) != NULL) {
        // Split input line into tokens
        
        inputPlate = strtok(fileOutput, " "); // Get the first token: inputPlate
        if (inputPlate == NULL) {
            // Handle error or break
            continue; // Skip this iteration if inputPlate is NULL (Empty line or invalid format)
        }

        string = strtok(NULL, " \n"); // Get the second token: mileage
        if (string == NULL) {
            // Handle error or continue
            continue; // Skip this iteration if string is NULL (Missing mileage)
        }
        mileage = atoi(string); // Convert string to integer

        // Process the car information
        // Assuming initializeCar and addList functions are properly defined
        // Car* car = initializeCar(mileage, dateNULL, inputPlate);
        // avail->next = addList(avail->next, car, 0);

        // Just for understanding, print out the values
        printf("Plate: %s, Mileage: %d\n", inputPlate, mileage);
    }

    fclose(filePointer);
    return 0;
}
