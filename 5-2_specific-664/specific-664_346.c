#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createdataset(int Datasetsize, const char *filename) {
    FILE *f;
    float v[Datasetsize];

    srand((unsigned int)time(NULL));

    for (int i = 0; i < Datasetsize; i++)
        v[i] = ((float)rand() / (float)(RAND_MAX)) * 100;

    f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(v, sizeof(float), Datasetsize, f);

    fclose(f);
}

void loadDataset(int DataSetSize, const char *filename, float *v) {
    FILE *fp;
    int s;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    s = fread(v, sizeof(float), DataSetSize, fp);
    printf("Number of records read: %d\n", s);

    for (int i = 0; i < s; i++) {
        printf("\t%f\n", v[i]);
    }

    fclose(fp);
}

int main() {
    int datasetsize;
    char filein[50];

    printf("Enter the size of the dataset: ");
    scanf("%d", &datasetsize);

    float v[datasetsize];

    printf("Enter input file name: ");
    scanf("%s", filein);

    createdataset(datasetsize, filein);
    loadDataset(datasize, filein, v);

    return 0;
}
