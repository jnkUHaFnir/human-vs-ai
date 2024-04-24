    #include <stdio.h>
    
    int main() {
        int m[10][5];
        int m_rows = 0;
        int m_cols = 5;
        FILE *fp = fopen("grades.txt", "r");
    
        if (!fp) {
            fprintf(stderr, "unable to open grades.txt");
            return 1;
        }
    
        // read 5-col matrix from file
        for (;; m_rows++) {
            int ret = fscanf(fp, "%d %d %d %d %d",
                             &m[m_rows][0], &m[m_rows][1], 
                             &m[m_rows][2], &m[m_rows][3], 
                             &m[m_rows][4]);
    
            if (ret == 0) {
                fprintf(stderr, "fscanf format error reading grades.txt");
                return 1;
            }
            else if (ret == EOF) break;
        }
    
        fclose(fp);
    
        // print the matrix
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                printf("%d ", m[i][j]);
            }
    
            puts("");
        }
    
        return 0;
    }