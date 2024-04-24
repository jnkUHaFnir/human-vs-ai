    #include <stdio.h>
    
    int main() {
        int i, j;
        int n[10][5];
        int n_rows = 0;
        int n_cols = 5;
        FILE *fp = fopen("read", "r");
    
        // read 5-col matrix from file
        for (; EOF != fscanf(fp, "%d %d %d %d %d",
               &n[n_rows][0], &n[n_rows][1], &n[n_rows][2], 
               &n[n_rows][3], &n[n_rows][4]); n_rows++);
    
        // print the matrix
        for (i = 0; i < n_rows; i++) {
            for (j = 0; j < n_cols; j++) {
                printf("%d ", n[i][j]);
            }
    
            puts("");
        }
    
        fclose(fp);
        return 0;
    }