void createdataset(int Datasetsize, char * filename) {
    FILE *f;
    int su;
    float* v = (float*) malloc(Datasetsize * sizeof(float));    

    srand((unsigned int)time(NULL));

    for(int i = 0; i < Datasetsize; i++) {
        *(v+i) = ((float)rand()/(float)(RAND_MAX)) * 100;
    }

    f = fopen(filename, "wb");
    su = fwrite(v, sizeof(float), Datasetsize , f);
    printf("%d\n", su);
    fclose(f);
    free(v);
}
void loadDataset (int DataSetSize, char *filename, float *v) {
    FILE *fp;
    int s;

    fp = fopen(filename, "rb");
    if( fp == NULL) {
        printf("File cant be opened");
        return;
    }

    s = fread(v, sizeof(float), DataSetSize, fp);
    printf("%d\n", s);
    for(int i=0; i<DataSetSize; i++) {
        printf("\t%f", *(v+i));
    }

    fclose(fp);
}
int main()  
{ 
    char ch;
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
