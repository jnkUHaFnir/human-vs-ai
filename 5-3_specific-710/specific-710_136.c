do
{
    fgets(buffer, 5000, matrixFP);
    jj=0;
    strtok(buffer, delim); // For the first token
    while(strtok(NULL, delim) != NULL)
    {
        jj++;
    }
    if(jj!=sizeX)
    {
        fileValid = 0;
    }
    ii++;
} while(!feof(matrixFP));

// Remove this line as splitString is not being allocated separately
// free(splitString);

free(buffer);
