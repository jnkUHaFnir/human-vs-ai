while(string != NULL)
{
    // Your code here...

    fgets(fileOutput,400,filePointer);
    inputPlate = strtok(fileOutput," ");
    string = strtok(NULL," ");
} 
