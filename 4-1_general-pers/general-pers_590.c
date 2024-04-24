#define MAX_LINE_LENGTH 400

char fileOutput[MAX_LINE_LENGTH];
char *inputPlate;
char *string;
int mileage;

fgets(fileOutput, MAX_LINE_LENGTH, filePointer); // Read in a line from the file

while (fgets(fileOutput, MAX_LINE_LENGTH, filePointer) != NULL)
{
    inputPlate = strtok(fileOutput, " "); // Take the first token, store into inputPlate

    while (string = strtok(NULL, " "))
    {
        mileage = atoi(string); // Convert from string to integer and store into mileage

        car = initializeCar(mileage, dateNULL, inputPlate);
        avail->next = addList(avail->next, car, 0);
    }
}

