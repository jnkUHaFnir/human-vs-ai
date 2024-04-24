#include <stdio.h>

// Define the maximum size for the grid
#define MAX_SIZE 8

int main() {
    int n = MAX_SIZE;
    char c[n+1][n+1];
    
    int i, j;
    int count = 0;
    int newi[4];
    int newj[4];
    int ind;

    // Initialization
    for (i = 0; i < n+1; i++) {
        for (j = 0; j < n+1; j++) {
            if (i == 0 || j == 0 || i == n || j == n) {
                c[i][j] = 'n';  // tagged as newly known
            } else if (i == 1 || j == 1 || i == n-1 || j == n-1) {
                c[i][j] = 't';  // trial points
            } else {
                c[i][j] = 'f';  // far away points
            }
        }
    }

    for (i = 0; i < n+1; i++) {
        for (j = 0; j < n+1; j++) {
            if (c[i][j] == 't') {
                count++;  // count is number of 't'
            }
        }
    }

    int ri[count]; // array that stores the row index of trial points
    int ci[count]; // array that stores the column index of trial points

    int k = 0;
    for (i = 0; i < n+1; i++) {
        for (j = 0; j < n+1; j++) {
            if (c[i][j] == 't') {
                ri[k] = i;
                ci[k] = j;
                k++;
            }
        }
    }

    while (count > 0) {
        int num = 0;
        i = ri[0];
        j = ci[0];
        c[i][j] = 'n';
        ri[0] = ri[count-1];
        ci[0] = ci[count-1];
        count--;

        int newcount = 0;
        if (c[i-1][j] == 'f') {
            c[i-1][j] = 't';
            newcount++;
            newi[newcount-1] = i-1;
            newj[newcount-1] = j;
        }
        if (c[i+1][j] == 'f') {
            c[i+1][j] = 't';
            newcount++;
            newi[newcount-1] = i+1;
            newj[newcount-1] = j;
        }
        if (c[i][j-1] == 'f') {
            c[i][j-1] = 't';
            newcount++;
            newi[newcount-1] = i;
            newj[newcount-1] = j-1;
        }
        if (c[i][j+1] == 'f') {
            c[i][j+1] = 't';
            newcount++;
            newi[newcount-1] = i;
            newj[newcount-1] = j+1;
        }

        count += newcount;

        // Use a temporary array for storing new indices
        int temp_ind = count - newcount;
        for (ind = 0; ind < newcount; ind++) {
            ri[temp_ind + ind] = newi[ind];
            ci[temp_ind + ind] = newj[ind];
        }
    }

    return 0;
}
