#define MAX_LINE_LENGTH 400

char fileOutput[MAX_LINE_LENGTH];
char *inputPlate;
char *string;
int mileage;

while (fgets(fileOutput, MAX_LINE_LENGTH, filePointer) != NULL) {
    inputPlate = strtok(fileOutput, " ");
    
    if (inputPlate == NULL) {
        // Handle empty line or other errors
        continue;
    }

    string = strtok(NULL, " ");
    
    if (string == NULL) {
        // Handle missing mileage value or other errors
        continue;
    }
    
    mileage = atoi(string);
    
    car = initializeCar(mileage, dateNULL, inputPlate);
    avail->next = addList(avail->next, car, 0);
}
