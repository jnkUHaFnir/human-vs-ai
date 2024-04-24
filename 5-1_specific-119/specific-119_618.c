fgets(fileOutput, 400, filePointer); // Read in a line from the file

inputPlate = strtok(fileOutput, " "); // Take the first token, store into inputPlate

while (1)
{
    if (inputPlate == NULL) {
        break; // Exit the loop if inputPlate is NULL
    }

    string = strtok(NULL," ");
    if (string == NULL) {
        break; // Exit the loop if no more tokens available
    }

    mileage = atoi(string); // Convert from string to integer and store into mileage

    car = initializeCar(mileage, dateNULL, inputPlate);
    avail->next = addList(avail->next, car, 0);

    fgets(fileOutput, 400, filePointer);
    inputPlate = strtok(fileOutput, " ");
}
