#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createdataset(int Datasetsize, char *filename) {
    FILE *f;
    float v[Datasetsize];

    srand((unsigned int)time(NULL));

    for (int i = 0; i < Datasetsize; i++) {
        v[i] = ((float)rand() / (float)(RAND_MAX)) * 100;
    }

    f = fopen(filename, "wb"); // Open in binary mode
    fwrite(v, sizeof(float), Datasetsize, f);
    fclose(f);
}

void loadDataset(int DataSetSize, char *filename, float *v) {
    FILE *fp;
    
    fp = fopen(filename, "rb"); // Open in binary mode
    if (fp == NULL) {
        printf("File can't be opened\n");
        return;
    }

    fread(v, sizeof(float), DataSetSize, fp);
    fclose(fp);

    for (int i = 0; i < DataSetSize; i++) {
        printf("\t%f", v[i]);
    }
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
