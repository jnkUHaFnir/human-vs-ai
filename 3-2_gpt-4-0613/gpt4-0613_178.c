#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_arrays(int* a, int* b, int size){
    for(int i = 0; i < size; i++){
        if(a[i] != b[i]) return -1;
    }
    return 0;
}

int **DoThis(int n, int arr[n]) {
    int l = n;
    int **b = malloc(l * sizeof(*b)); 
    int i, j, k;
    for (i = 0; i < l; i++) {
        j = (i + 1) % l;
        int *copy = malloc(l * sizeof(*copy));
        for (k = 0; k < l; k++)
            copy[k] = arr[k];
        int t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;
        b[i] = copy;
    }
    return b;
}

int DoItUntilWeFindIt(int n, int start[n], int end[n], int level){
    if(compare_arrays(start, end, n) == 0) return level;

    int** produced_arrays = DoThis(n, start);
    for(int i=0; i<n; i++){
        int result = DoItUntilWeFindIt(n, produced_arrays[i], end, level+1);
        if(result != -1) return result;
    }
    return -1;
}

int main(){
    int a[] = {2,3,4,1};
    int b[] = {1,2,4,3};
    int size = sizeof(a)/sizeof(int);

    int level = DoItUntilWeFindIt(size, a, b, 0);
    printf("Level: %d\n", level);
    return 0;
}
