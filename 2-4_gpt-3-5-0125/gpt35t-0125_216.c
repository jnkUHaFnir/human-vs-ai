void makeArray(int scores[][COLS], FILE *ifp){
    int i=0, j=0, num, numrows = 7, numcols = 14;

    for(i = 0; i < numrows; ++i){
        for(j = 0; j < numcols; ++j){
            fscanf(ifp, "%d", &num);
            scores[i][j] = num;
        }
    }
}

int main(){
    int scoreArray[ROWS][COLS];
    int i=0, j=0;
    FILE *ifp;
    ifp = fopen("scores.txt", "r");

    makeArray(scoreArray, ifp);

    // Print the values in the array to verify
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            printf("%d ", scoreArray[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;   
}
