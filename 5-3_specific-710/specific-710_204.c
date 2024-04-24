#include <stdio.h>

int main() {
    FILE *myFile;
    myFile = fopen("numbers.txt", "r");
    if (myFile == NULL) {
        printf("Error Reading File\n");
        return 1;
    }

    int redica[100]; // Assuming array size is 100
    int i = 0;
    
    while (fscanf(myFile, "%d", &redica[i]) != EOF) {
        i++;
    }
    
    fclose(myFile);

    for (int j = 0; j < i; j++) {
        printf("%d\n", redica[j]);
    }

    return 0;
}
