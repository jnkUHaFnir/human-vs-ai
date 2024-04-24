void makeArray(int scores[][COLS], FILE *ifp){
    int i=0, j=0, numrows = 7, numcols = 14;

    for(i = 0; i < numrows; ++i){
        for(j = 0; j < numcols; ++j){
            fscanf(ifp, "%d", &num); // Reading a number from the file into num.
            scores[i][j] = num; // This is the corrected line.
        }
    }
}
#define ROWS 7    // Ensure this is consistent with numrows.
#define COLS 14   // Ensure this is consistent with numcols.
#include <stdio.h>
#include <stdlib.h>

#define ROWS 7
#define COLS 14

void makeArray(int scores[][COLS], FILE *ifp){
    int i=0, j=0, num, numrows = 7, numcols = 14;

    for(i = 0; i < numrows; ++i){
        for(j = 0; j < numcols; ++j){
            fscanf(ifp, "%d", &num); // Reading number into num.
            scores[i][j] = num; // Assigning num to the correct spot in the array.
        }
    }
}

int main(){
    int scoreArray[ROWS][COLS];
    FILE *ifp;
    
    ifp = fopen("scores.txt", "r");
    if (ifp == NULL) {
        printf("Error opening file\n");
        return 1; // Exit the program if file cannot be opened.
    }
    
    makeArray(scoreArray, ifp);

    // optionally, you may wish to add code here to print the array's contents to verify it was filled correctly.
    
    fclose(ifp); // Don't forget to close the file when you're done with it.
    
    system("pause"); // Note: system("pause") is generally not portable. Consider alternative ways for pausing.
    return 0;   
}
