#define MAX_LINE_LENGTH 400

char fileOutput[MAX_LINE_LENGTH];
char* inputPlate;
char* mileageString;
int mileage;
while (fgets(fileOutput, MAX_LINE_LENGTH, filePointer) != NULL) {
    inputPlate = strtok(fileOutput, " ");
    if (inputPlate == NULL) {
        // Handle case where no plate number is found
        continue;
    }

    mileageString = strtok(NULL, " ");
    if (mileageString == NULL) {
        // Handle case where no mileage is found
        continue;
    }

    mileage = atoi(mileageString);
    car = initializeCar(mileage, dateNULL, inputPlate);
    avail->next = addList(avail->next, car, 0);
}
