#include <stdio.h>

#define MAX_NUMBERS 100

int main() {
    FILE *myFile;
    myFile = fopen("numbers.txt", "r");
    if (myFile == NULL) {
        printf("Error Reading File\n");
        return 1; // Return from main due to file reading error
    }

    int redica[MAX_NUMBERS];
    int tek;
    int i = 0;

    while (fscanf(myFile, "%d", &tek) == 1 && i < MAX_NUMBERS) {
        redica[i] = tek;
        i++;
    }

    fclose(myFile);

    // Output the numbers from the array
    for (int j = 0; j < i; j++) {
        printf("%d ", redica[j]);
    }

    return 0;
}
