void createdataset(int Datasetsize, char *filename)
{
    FILE *f;
    float value;

    srand((unsigned int)time(NULL));

    f = fopen(filename, "wb");

    for(int i = 1; i <= Datasetsize; i++) {
        value = ((float)rand() / (float)(RAND_MAX)) * 100;
        fwrite(&value, sizeof(float), 1, f);
    }

    fclose(f);
}

void loadDataset(int DataSetSize, char *filename, float *v)
{
    FILE *fp;
    int s;

    fp = fopen(filename, "rb");
    if (fp == NULL) 
        printf("File can't be opened");

    for (int i = 0; i < DataSetSize; i++) {
        fread(&v[i], sizeof(float), 1, fp);
    }

    fclose(fp);
}

int main()  
{ 
    int datasetsize;
    char filein[50];

    printf("Enter the size of the dataset: ");
    scanf("%d", &datasetsize);

    float v[datasetsize];

    printf("Enter input file name: ");
    scanf("%s", filein);

    createdataset(datasetsize, filein);
    loadDataset(datasetsize, filein, v);

    return 0;
}
