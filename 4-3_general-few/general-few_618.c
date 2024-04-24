fgets(fileOutput, 400, filePointer); // Read in a line from the file

inputPlate = strtok(fileOutput, " "); // Take the first token, store into inputPlate

while(inputPlate != NULL) // Check strtok result for NULL
{
    string = strtok(NULL, " ");
    if (string == NULL) {
        break; // Exit loop if no more tokens
    }
    
    mileage = atoi(string); // Convert from string to integer and store into mileage

    car = initializeCar(mileage, dateNULL, inputPlate);
    avail->next = addList(avail->next, car, 0);

    inputPlate = strtok(NULL, " "); // Get the next token from the same input string
}
