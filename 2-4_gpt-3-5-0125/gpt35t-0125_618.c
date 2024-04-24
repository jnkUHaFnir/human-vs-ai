fgets(fileOutput, 400, filePointer); // Read in a line from the file

while (fileOutput != NULL)
{
    inputPlate = strtok(fileOutput, " "); // Take the first token, store into inputPlate

    // Continue processing only if inputPlate is not NULL
    if (inputPlate != NULL)
    {
        string = strtok(NULL, " ");
        if (string != NULL)
        {
            mileage = atoi(string); // Convert from string to integer and store into mileage

            car = initializeCar(mileage, dateNULL, inputPlate);
            avail->next = addList(avail->next, car, 0);
        }
    }

    fgets(fileOutput, 400, filePointer);
}
