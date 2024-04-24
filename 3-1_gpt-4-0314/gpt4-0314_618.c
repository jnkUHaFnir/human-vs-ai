char fileOutput[400];
char* inputPlate;
char* string;
int mileage;
Car* car;

while (fgets(fileOutput, 400, filePointer) != NULL) // Read in a line from the file
{
    inputPlate = strtok(fileOutput, " "); // Take the first token, store into inputPlate

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
}
