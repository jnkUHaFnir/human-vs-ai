void createdataset(int Datasetsize, char *filename) {
    FILE *f;
    int su;
    float v[Datasetsize];

    srand((unsigned int)time(NULL));

    for (int i = 0; i < Datasetsize; i++) 
        v[i] = ((float)rand() / (float)(RAND_MAX)) * 100;

    f = fopen(filename, "wb");
    su = fwrite(v, sizeof(float), Datasetsize, f);
    printf("%d\n", su);
    fclose(f);
}

void loadDataset(int DataSetSize, char *filename, float *v) {
    FILE *fp;
    int s;

    fp = fopen(filename, "rb");
    if (fp == NULL) 
        printf("File can't be opened");

    s = fread(v, sizeof(float), DataSetSize, fp);
    printf("%d\n", s);
    for (int i = 0; i < DataSetSize; i++) {
        printf("\t%f", v[i]);
    }

    fclose(fp);
}
