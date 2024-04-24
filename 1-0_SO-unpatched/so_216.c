    void makeArray(int scores[][COLS], FILE *ifp) {
        int i=0, j=0, num, numrows = 7, numcols = 14, ch;
        for (i=0; i < numrows; ++i) {
            for (j=0; j < numcols; ++j) {
                while (((ch = getc(ifp)) != EOF) && (ch == ' ')) // eat all spaces
                if (ch == EOF) break;                            // end of file -> break
                ungetc(ch, ifp);
                if (fscanf("%d", &num) != 1) break;
                scores[i][j] = num;                              // store the number
            }
        }
    }