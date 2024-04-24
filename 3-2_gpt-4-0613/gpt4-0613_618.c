while(fgets(fileOutput, 400, filePointer) != NULL) // fgets returns NULL when it reaches EOF
{
    inputPlate = strtok(fileOutput," ");

    if(inputPlate != NULL)
    {
       string = strtok(NULL," ");
       if(string != NULL)
       {
           mileage = atoi(string); //Convert from string to integer and store into mileage

           car = initializeCar(mileage,dateNULL,inputPlate);
           avail->next = addList(avail->next,car,0);
       }
       else
       {
           printf("Failed to fetch mileage token\n");
       }
    }
    else
    {
       printf("Failed to fetch inputPlate token\n");
    }
} 
