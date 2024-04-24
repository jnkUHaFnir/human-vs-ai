#define MAX_FILE_NAME_SIZE 50

void createDataset(int datasetSize, char *filename) {
    FILE *f;
    float v[datasetSize];    

    srand((unsigned int)time(NULL));

    for(int i = 0; i < datasetSize; i++) {
        v[i] = ((float)rand() / RAND_MAX) * 100;
    }

    f = fopen(filename, "wb");
    fwrite(v, sizeof(float), datasetSize, f);
    fclose(f);
}

void loadDataset(int datasetSize, char *filename, float *v) {
    FILE *fp;
    int s;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("File can't be opened\n");
        return;
    }

    s = fread(v, sizeof(float), datasetSize, fp);
    printf("%d\n", s);
    for (int i = 0; i < datasetSize; i++) {
        printf("\t%f", v[i]);
    }

    fclose(fp);
}

int main() {
    int datasetSize;
    char fileIn[MAX_FILE_NAME_SIZE];

    printf("Enter the size of the dataset: ");
    scanf("%d", &datasetSize);

    float v[datasetSize];

    printf("Enter input file name: ");
    scanf("%s", fileIn);

    createDataset(datasetSize, fileIn);
    loadDataset(datasetSize, fileIn, v);

    return 0;
}
