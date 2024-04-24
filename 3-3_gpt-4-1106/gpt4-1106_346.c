void createdataset(int Datasetsize, char *filename)
{
    FILE *f;
    int su;
    float *v = (float *)malloc(Datasetsize * sizeof(float)); // Use dynamic allocation

    srand((unsigned int)time(NULL));

    for (int i = 0; i < Datasetsize; i++) // Arrays start at index 0
        v[i] = ((float)rand() / (float)(RAND_MAX)) * 100;

    f = fopen(filename, "wb");
    su = fwrite(v, sizeof(float), Datasetsize, f);
    printf("%d\n", su);
    fclose(f);

    free(v); // Don't forget to free the allocated memory
}
void loadDataset(int DataSetSize, char *filename, float *v)
{
    FILE *fp;
    int s;

    fp = fopen(filename, "rb"); // Use "rb" to read binary data
    if (fp == NULL) {
        printf("File can't be opened\n");
        return;
    }

    s = fread(v, sizeof(float), DataSetSize, fp);
    printf("%d\n", s);

    for (int i = 0; i < DataSetSize; i++) {
        printf("\t%f", v[i]); // Use v[i] instead of *(v+i)
    }

    fclose(fp);
}
int main() // Use int main for proper standard adherence
{
    int datasetsize;
    char filein[50];
 
    printf("Enter the size of the datasetsize: ");
    scanf("%d", &datasetsize);

    float *v = (float *)malloc(datasetsize * sizeof(float)); // Dynamic allocation

    printf("%d\n", datasetsize);
    printf("Enter input file name: ");
    scanf("%49s", filein); // Limit input size to avoid buffer overflow
    printf("%s\n", filein);

    createdataset(datasetsize, filein);
    loadDataset(datasetsize, filein, v);

    free(v); // Free the dynamically allocated memory

    return 0; // Return an exit code
}
