#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void readFromFile() {
    FILE *myfile;
    int currentSz = 10;
    int maxSz = 1000010;

    while (currentSz <= maxSz) {
        float *fileArr = (float*)malloc(currentSz * sizeof(float));

        char fileName[200];
        fileName[0] = '\0';
        strcat(fileName, "C:\\Users\\MatthewC\\Documents\\HonorsProject341\\RandomFloats\\");

        char sizeStr[50];
        sprintf(sizeStr, "%d", currentSz);
        strcat(sizeStr, "Floats.txt");
        strcat(fileName, sizeStr);
        
        myfile = fopen(fileName, "r");

        int iterator;
        for (iterator = 0; iterator < currentSz; iterator++) {
            fscanf(myfile, "%f", &fileArr[iterator]);
        }

        clock_t start = clock(), diff;
        heapSort(fileArr, currentSz);
        diff = clock() - start;

        int millisec = diff * 1000000 / CLOCKS_PER_SEC;
        
        printf("size: %d runtime: %d\n", currentSz, millisec);
        fclose(myfile);

        free(fileArr); // Free the dynamically allocated memory

        currentSz += 20000;
    }
}

int main() {
    readFromFile();
    return 0;
}
