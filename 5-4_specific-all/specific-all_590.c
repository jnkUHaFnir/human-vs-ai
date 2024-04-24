fgets(fileOutput, 400, filePointer); // Read in a line from the file

inputPlate = strtok(fileOutput, " "); // Take the first token, store into inputPlate

while (inputPlate != NULL)
{
    string = strtok(NULL, " ");
    if (string == NULL) {
        break; // Handle case where there are no more tokens
    }

    mileage = atoi(string); // Convert from string to integer and store into mileage

    car = initializeCar(mileage, dateNULL, inputPlate);
    avail->next = addList(avail->next, car, 0);

    fgets(fileOutput, 400, filePointer);
    if (fileOutput != NULL) {
        inputPlate = strtok(fileOutput, " ");
    } else {
        inputPlate = NULL;
    }
}
