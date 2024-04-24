while (fgets(fileOutput, 400, filePointer) != NULL) {
    inputPlate = strtok(fileOutput, " "); // Take the first token, store into inputPlate

    if (inputPlate == NULL) {
        break; // Exit the loop if inputPlate is NULL
    }

    while (inputPlate != NULL) {
        char* string = strtok(NULL, " ");
        if (string == NULL) {
            break; // Exit the loop if string is NULL
        }
        
        int mileage = atoi(string); // Convert from string to integer and store into mileage

        // Assuming initializeCar and addList functions work correctly
        car = initializeCar(mileage, dateNULL, inputPlate);
        avail->next = addList(avail->next, car, 0);

        inputPlate = strtok(NULL, " ");
    }
}
