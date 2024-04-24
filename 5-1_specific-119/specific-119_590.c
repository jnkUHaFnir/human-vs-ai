fgets(fileOutput, 400, filePointer); // Read in a line from the file

while (fileOutput != NULL)
{
    inputPlate = strtok(fileOutput, " "); // Tokenizing the line

    if (inputPlate == NULL) {
        break; // End of file reached
    }

    string = strtok(NULL, " ");
    mileage = atoi(string); // Convert from string to integer and store into mileage

    car = initializeCar(mileage, dateNULL, inputPlate);
    avail->next = addList(avail->next, car, 0);

    fgets(fileOutput, 400, filePointer); // Read next line

    // Check if read was successful
    if (fileOutput == NULL) {
        break;
    }

    inputPlate = strtok(fileOutput, " "); // Tokenizing the next line
}
