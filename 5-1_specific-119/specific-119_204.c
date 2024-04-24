#include <stdio.h>

#define MAX_NUMBERS 100

int main() {
    FILE *myFile;
    myFile = fopen("numbers.txt", "r");

    if (myFile == NULL) {
        printf("Error Reading File\n");
        return 1;
    }

    int redica[MAX_NUMBERS];
    int tek, i;

    i = 0;
    while (fscanf(myFile, "%d", &tek) == 1) {
        redica[i] = tek;
        i++;

        if (i >= MAX_NUMBERS) {
            printf("Exceeded maximum number of elements for the array\n");
            break;
        }
    }

    fclose(myFile);

    for (int j = 0; j < i; j++) {
        printf("%d\n", redica[j]);
    }

    return 0;
}
