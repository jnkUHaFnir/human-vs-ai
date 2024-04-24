#include <stdio.h>

int main(int argc, char *argv[]) {
    int nrows, ncols;
    char filename[100];
    FILE *infile;

    // get filename from command line argument
    sprintf(filename, "%s", argv[1]);

    // open file for reading
    infile = fopen(filename, "r");
    if (infile == NULL) {
        printf("Failed to open file %s\n", filename);
        return 1;
    }

    // read number of rows and columns from file
    fscanf(infile, "%d %d", &nrows, &ncols);

    // allocate memory for data
    int *data = (int*) malloc(nrows * ncols * sizeof(int));

    // read data from file
    for (int i=0; i<nrows*ncols; i++) {
        fscanf(infile, "%d", &data[i]);
    }

    // close file
    fclose(infile);

    // print data
    for (int i=0; i<nrows*ncols; i++) {
        printf("%d ", data[i]);
        if ((i+1) % ncols == 0) printf("\n");
    }

    // free memory
    free(data);

    return 0;
}
