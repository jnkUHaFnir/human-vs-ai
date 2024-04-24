fgets(fileOutput, 400, filePointer);

while (inputPlate != NULL)
{
    mileage = atoi(strtok(NULL, " ")); //Convert from string to integer and store into mileage
    
    car = initializeCar(mileage, dateNULL, inputPlate);
    avail->next = addList(avail->next, car, 0);

    inputPlate = strtok(NULL, " ");
} 
