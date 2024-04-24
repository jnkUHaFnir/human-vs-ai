#include <stdio.h>

#define MAX_NUMBERS 100

int main() {
    FILE *myFile;
    int redica[MAX_NUMBERS];
    int tek;
    int i = 0;

    myFile = fopen("numbers.txt", "r");
    
    if (myFile == NULL) {
        printf("Error Opening File\n");
        return 1;
    }

    while (fscanf(myFile, "%d", &tek) == 1) { // Read numbers from file
        if (i < MAX_NUMBERS) {
            redica[i] = tek;
            i++;
        } else {
            printf("Exceeded maximum number of elements\n");
            break;
        }
    }

    fclose(myFile);

    // Print the numbers stored in the array
    for (int j = 0; j < i; j++) {
        printf("%d\n", redica[j]);
    }

    return 0;
}
