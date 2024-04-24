/* ... earlier code ... */

// Remove the malloc call for splitString; it's not needed.
buffer = malloc(5000*sizeof(char));
do
{
    fgets(buffer, 5000, matrixFP);
    jj=0;
    splitString = strtok(buffer, delim);
    while(splitString != NULL)
    {
        jj++;
        splitString = strtok(NULL, delim);
    }
    if(jj!=sizeX)
    {
        fileValid = 0;
    }
    ii++;
} while(!feof(matrixFP));
if(ii != sizeY || buffer==NULL)
{
    fileValid = 0;
}

// No need to free splitString; it was never allocated.
free(buffer);

/* ... later code ... */

return matrix;
while(fgets(buffer, 5000, matrixFP) != NULL) {
    // ... process each line ...
}
