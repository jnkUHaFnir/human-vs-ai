fgets(fileOutput, 400, filePointer); // Read in a line from the file

inputPlate = strtok(fileOutput, " "); // Take the first token, store into inputPlate

while (fileOutput != NULL)
{
    string = strtok(NULL, " ");
    if (string == NULL) {
        break; // Exit the loop when no more tokens are found
    }

    mileage = atoi(string); // Convert from string to integer and store into mileage

    // Your remaining code here

    fgets(fileOutput, 400, filePointer);
    inputPlate = strtok(fileOutput, " ");
}
