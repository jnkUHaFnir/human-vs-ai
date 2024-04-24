#include <stdio.h>

int main() {
    FILE *myFile;
    myFile = fopen("numbers.txt", "r");
    if (myFile == NULL) {
        printf("Error Opening File\n");
        return 1;
    }
    
    int redica[100]; // Assuming a maximum of 100 numbers in the file
    int i, tek;
    
    for (i = 0; i < 100; i++) { // Assuming a maximum of 100 numbers to read
        if (fscanf(myFile, "%d", &tek) != 1) {
            break; // Exit the loop if fscanf fails to read an integer
        }
        redica[i] = tek;
    }
    
    fclose(myFile);

    // Print the numbers read from the file
    printf("Numbers in file:\n");
    for (int j = 0; j < i; j++) {
        printf("%d ", redica[j]);
    }
    printf("\n");
    
    return 0;
}
