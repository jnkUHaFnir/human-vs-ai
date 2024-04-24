#define ROWS 7
#define COLS 14

void makeArray(int scores[][COLS], FILE *ifp){
    int i, j, num;

    for(i = 0; i < ROWS; ++i){
        for(j = 0; j < COLS; ++j){
            fscanf(ifp, "%d", &num);
            scores[i][j] = num; // Assign num to scores[i][j]
        }
    }
}
int main(){
    int scoreArray[ROWS][COLS];
    int i, j;
    FILE *ifp;
    ifp = fopen("scores.txt", "r");

    if (ifp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    makeArray(scoreArray, ifp);

    fclose(ifp); // Close the file after reading

    system("pause");
    return 0;   
}
