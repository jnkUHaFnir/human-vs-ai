splitString = strtok(buffer, delim);
int** readMatrixFile(char* inFileName, int** matrix, int sizeY, int sizeX)
{
    FILE* matrixFP;
    int ii=0, jj=0, fileValid = 1;
    char *buffer, *splitString, *token;
    const char delim[]=" \n\r";

    matrixFP = fopen(inFileName, "r");
    if(matrixFP != NULL)
    {
        /*Check if file is the same size as specified by the command line
         *assumed valid until the file is checked*/
        buffer = malloc(5000*sizeof(char));
        do
        {
            fgets(buffer, 5000, matrixFP);
            jj=0;
            token = strtok(buffer, delim);
            while(token != NULL)
            {
                splitString = token; // This line is not necessary but it keeps the original logic
                jj++;
                token = strtok(NULL, delim);
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

        free(buffer);

        if(fileValid) /*Files match to specified command line values*/
        {
            ii=0;
            rewind(matrixFP);
            matrix = (int**)malloc(sizeY * sizeof(int *));
            do
            {
                matrix[ii] = (int*)malloc(sizeX * sizeof(int));
                jj=0;
                do
                {
                    fscanf(matrixFP, "%d", &matrix[ii][jj]);
                    jj++;
                } while(jj<sizeX);
                ii++;
            } while(ii<sizeY && !feof(matrixFP));
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
