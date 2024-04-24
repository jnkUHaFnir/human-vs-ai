#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void createdataset(int Datasetsize, char *filename)
{
    FILE *f;
    float v[Datasetsize];

    srand((unsigned int)time(NULL));

    for (int i = 0; i < Datasetsize; i++)
        v[i] = ((float)rand() / (float)(RAND_MAX)) * 100;

    f = fopen(filename, "wb");
    fwrite(v, sizeof(float), Datasetsize, f);
    fclose(f);
}

void loadDataset(int DataSetSize, char *filename, float *v)
{
    FILE *fp;
    int s;

    fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        printf("File can't be opened");
        return;
    }

    s = fread(v, sizeof(float), DataSetSize, fp);
    printf("%d\n", s);
    for(int i = 0; i < DataSetSize; i++)
    {
        printf("\t%f", v[i]);
    }

    fclose(fp);
}

int main()
{
    int datasetsize;
    char filein[50];

    printf("Enter the size of the datasetsize: ");
    scanf("%d", &datasetsize);

    float v[datasetsize];

    printf("%d\n", datasetsize);
    printf("Enter input file name: ");
    scanf("%s", filein);
    printf("%s\n", filein);
    createdataset(datasetsize, filein);
    loadDataset(datasetsize, filein, v);

    return 0;
}
