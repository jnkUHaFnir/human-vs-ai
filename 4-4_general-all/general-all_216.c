#define ROWS 7
#define COLS 14

void makeArray(int scores[][COLS], FILE *ifp){
    int i, j;

    for(i = 0; i < ROWS; ++i){
        for(j = 0; j < COLS; ++j){
            if(fscanf(ifp, "%d", &scores[i][j]) != 1){
                // Handle error if fscanf fails to read an integer
                printf("Error: Unable to read integer from file.\n");
                exit(1); // Exit the program (or handle the error appropriately)
            }
        }
    }
}
