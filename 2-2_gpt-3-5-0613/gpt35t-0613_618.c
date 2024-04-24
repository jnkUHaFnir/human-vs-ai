fgets(fileOutput, 400, filePointer);
inputPlate = strtok(fileOutput, " ");

while (inputPlate != NULL) {
    string = strtok(NULL, " ");
    if (string == NULL) {
        break;  // exit the loop if no more tokens are available
    }
    mileage = atoi(string); // Convert from string to integer and store into mileage

    car = initializeCar(mileage, dateNULL, inputPlate);
    avail->next = addList(avail->next, car, 0);

    fgets(fileOutput, 400, filePointer);
    inputPlate = strtok(fileOutput, " ");
}
