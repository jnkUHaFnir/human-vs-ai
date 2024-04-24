#include <stdio.h>
#include <stdlib.h> // For exit() in case of file opening failure
int tek = 0; // Variable to store each number read.
int i = 0; // Loop counter.
int redica[100]; // Example array to store read numbers. You might want to dynamically determine its size based on file content or use dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *myFile;
    int tek, i = 0;
    int redica[100]; // Assuming a maximum of 100 elements for demonstration.

    myFile = fopen("numbers.txt", "r");
    if (myFile == NULL) {
        printf("Error Reading File\n");
        exit(1); // Exits the program if file cannot be opened.
    } else {
        // Read numbers until end of file or array capacity is reached.
        while (fscanf(myFile, "%d", &tek) == 1) {
            redica[i++] = tek;
        }
        fclose(myFile); // Close the file after reading.

        // For demonstration, print the numbers read.
        for (int j = 0; j < i; j++) {
            printf("%d ", redica[j]);
        }
    }

    getch(); // Note: getch() is typically used in Windows/console specific programs. Consider using getchar() if portability is desired.
    return 0;
}
