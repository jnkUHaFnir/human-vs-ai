char fileOutput[400];
while (fgets(fileOutput, sizeof(fileOutput), filePointer) != NULL) // Read line
{
    inputPlate = strtok(fileOutput, " "); // Take the first token, store into inputPlate
    if (inputPlate == NULL) {
        // Handle error: Line doesn't contain a space
        continue; // Skip this line or break; depending on your needs
    }

    string = strtok(NULL, " \n"); // Attempt to take the second token, and consider newline delimiter
    if (string == NULL) {
        // Handle error: No mileage found on this line
        continue; // Skip this line or break; depending on your needs
    }
    
    mileage = atoi(string); // Convert from string to integer and store into mileage

    // Assuming initializeCar and addList functions work correctly and dateNULL is defined elsewhere
    car = initializeCar(mileage, dateNULL, inputPlate);
    avail->next = addList(avail->next, car, 0);
}
