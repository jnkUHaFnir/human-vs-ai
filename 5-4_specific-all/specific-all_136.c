char *tmpSplitString; // Temporary pointer to keep track of memory allocated by malloc

do
{
    fgets(buffer, 5000, matrixFP);
    jj=0;
    splitString = strtok(buffer, delim);
    while(splitString != NULL)
    {
        jj++;
        // Update tmpSplitString with current splitString before changing it
        tmpSplitString = splitString;
        splitString = strtok(NULL, delim);
    }

    // Free the previously allocated memory pointed by splitString
    free(tmpSplitString);

    if(jj!=sizeX)
    {
        fileValid = 0;
    }
    ii++;
} while(!feof(matrixFP));
