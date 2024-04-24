#define ROWS 7
#define COLS 14

void makeArray(int scores[][COLS], FILE *ifp){
    int i, j, num;

    for(i = 0; i < ROWS; ++i){
        for(j = 0; j < COLS; ++j){
            if(fscanf(ifp, "%d", &num) == 1) {
                scores[i][j] = num;
            } else {
                // Handle invalid input or end of file
                printf("Error reading from file or end of file reached.\n");
                return;
            }
        }
    }
}

int main(){
    int scoreArray[ROWS][COLS];
    int i, j;
    FILE *ifp;
    ifp = fopen("scores.txt", "r");

    if(ifp == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    makeArray(scoreArray, ifp);

    // Printing the read values for debugging
    for(i = 0; i < ROWS; ++i){
        for(j = 0; j < COLS; ++j){
            printf("%d ", scoreArray[i][j]);
        }
        printf("\n");
    }

    fclose(ifp);

    return 0;   
}
