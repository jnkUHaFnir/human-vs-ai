#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createdataset(int Datasetsize, char *filename) {
    FILE *f;
    float *v = (float*)malloc(Datasetsize * sizeof(float));

    srand((unsigned int)time(NULL));

    for (int i = 0; i < Datasetsize; i++) {
        v[i] = ((float)rand() / (float)(RAND_MAX)) * 100;
    }

    f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Error opening file\n");
        free(v);
        return;
    }

    fwrite(v, sizeof(float), Datasetsize, f);
    fclose(f);
    free(v);
}

void loadDataset(int DataSetSize, char *filename, float *v) {
    FILE *fp;
    int s;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    s = fread(v, sizeof(float), DataSetSize, fp);
    if (s != DataSetSize) {
        printf("Error reading file\n");
    } else {
        for (int i = 0; i < DataSetSize; i++) {
            printf("\t%f\n", v[i]);
        }
    }

    fclose(fp);
}

int main() {
    int datasetsize;
    char filein[50];

    printf("Enter the size of the datasetsize: ");
    scanf("%d", &datasetsize);

    float *v = (float*)malloc(datasetsize * sizeof(float));

    printf("Enter input file name: ");
    scanf("%s", filein);

    createdataset(datasetsize, filein);
    loadDataset(datasetsize, filein, v);

    free(v);

    return 0;
}
