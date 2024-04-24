int** readMatrixFile(char* inFileName, int** matrix, int sizeY, int sizeX)
{
    FILE* matrixFP;
    int ii=0, jj=0, fileValid = 1;
    char *buffer, *splitString; // No need to allocate memory for splitString here.
    const char delim[]=" \n\r";

    matrixFP = fopen(inFileName, "r");
    if(matrixFP != NULL)
    {
        buffer = malloc(5000*sizeof(char));
        if(buffer == NULL)
        {
            perror("Memory allocation failed");
            fclose(matrixFP);
            return NULL;
        }
        
        do
        {
            if(fgets(buffer, 5000, matrixFP) == NULL) break; // Check for NULL in case of end of file or error.
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
        } while(!feof(matrixFP) && fileValid); // Consider fileValidity in loop condition.
        
        if(ii != sizeY)
        {
            fileValid = 0;
        }

        free(buffer); // Only buffer needs to be freed.

        if(fileValid)
        {
            matrix = (int**)malloc(sizeY * sizeof(int *));
            if(matrix == NULL)
            {
                perror("Memory allocation failed");
                fclose(matrixFP);
                return NULL;
            }
            for(ii = 0; ii < sizeY; ii++)
            {
                matrix[ii] = (int*)malloc(sizeX * sizeof(int));
                if(matrix[ii] == NULL)
                {
                    perror("Memory allocation failed");
                    // Free previously allocated memory before returning.
                    while(--ii >= 0) free(matrix[ii]);
                    free(matrix);
                    fclose(matrixFP);
                    return NULL;
                }
            }

            rewind(matrixFP);
            for(ii = 0; ii < sizeY; ii++)
            {
                for(jj = 0; jj < sizeX; jj++)
                {
                    if(fscanf(matrixFP, "%d", &matrix[ii][jj]) != 1)
                    {
                        // Handle read error or incomplete read.
                        perror("Failed to read the expected number of elements");
                        // Consider adding cleanup here similar to the above error handling.
                        fclose(matrixFP);
                        return matrix; // or handle differently if preferred.
                    }
                }
            }
        }
        else
        {
            printf("Error: File does not match size specified by the command line\n");
        }
        fclose(matrixFP);
    }
    else
    {
        perror("Error: File does not exist or is invalid");
        matrix = NULL;
    }

    return matrix;
}
