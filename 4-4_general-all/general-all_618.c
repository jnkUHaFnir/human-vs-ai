char fileOutput[400];
char *inputPlate;
char *string;
int mileage;
// Other relevant code

fgets(fileOutput, 400, filePointer);

inputPlate = strtok(fileOutput, " ");

while (inputPlate != NULL)
{
    string = strtok(NULL, " ");
    if (string == NULL) {
        // Handle case where there's no more tokens in the line
        break;
    }
    
    mileage = atoi(string); // Convert from string to integer
    car = initializeCar(mileage, dateNULL, inputPlate);
    avail->next = addList(avail->next, car, 0);

    fgets(fileOutput, 400, filePointer);
    if (fileOutput != NULL) {
        inputPlate = strtok(fileOutput, " ");
    } else {
        // Handle end of file or other issues with reading lines
        break;
    }
}
