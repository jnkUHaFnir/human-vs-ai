void makeArray(int scores[][COLS], FILE *ifp){
    int i = 0, j = 0, num, numrows = 7, numcols = 14;

    for(i = 0; i < numrows; ++i){
        for(j = 0; j < numcols; ++j){
            fscanf(ifp, "%d", &num);
            scores[i][j] = num; // Correct assignment
        }
    }
}
