fgets(fileOutput, 400, filePointer); // Read in a line from the file

while (fileOutput != NULL) {
    inputPlate = strtok(fileOutput, " "); // Take the first token, store into inputPlate

    if (inputPlate != NULL) {
        string = strtok(NULL, " ");
        
        if (string != NULL) {
            mileage = atoi(string); // Convert from string to integer and store into mileage

            car = initializeCar(mileage, dateNULL, inputPlate);
            avail->next = addList(avail->next, car, 0);
        } else {
            // Handle case where mileage token is missing
            // You can log an error, skip the line, or take appropriate action
        }
    } else {
        // Handle case where inputPlate token is missing
        // You can log an error, skip the line, or take appropriate action
    }

    fgets(fileOutput, 400, filePointer);
}
