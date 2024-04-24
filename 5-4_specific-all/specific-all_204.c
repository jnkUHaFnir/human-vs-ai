#include <stdio.h>

#define MAX_NUMBERS 100

int main() {
    FILE *myFile;
    myFile = fopen("numbers.txt", "r");
    if (myFile == NULL) {
        printf("Error Reading File\n");
        return 1; // Exit program with an error code
    }

    int redica[MAX_NUMBERS];
    int tek, i;

    for (i = 0; i < MAX_NUMBERS; i++) {
        if (fscanf(myFile, "%d", &tek) == 1) {
            redica[i] = tek;
        } else {
            break; // Exit the loop if we can't read an integer
        }
    }

    fclose(myFile); // Don't forget to close the file

    // Print the numbers that were read
    for (int j = 0; j < i; j++) {
        printf("%d\n", redica[j]);
    }

    return 0;
}
