#include <stdio.h>

void sort(int a[], int len) {
    int i, j, t;

    for (i = 0; i < len; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void numberOfTimes(int a[], int al, int b[], int bl) {
    int i, p, c;

    for (i = 0; i < al; i++) {
        c = 0;
        for (p = 0; p < bl; p++) {
            if (a[i] == b[p]) {
                c++;       // This line should work now.
            }
        }   
        printf("(%d, %d) ", a[i], c);
    }
}

int main() {
    int maxarraylen = 1000;
    int a[maxarraylen];
    int b[maxarraylen];
    int al = 0, bl = 0;

    printf("Type elements of A separated by spaces. Do not enter duplicates (type '-1' to stop): ");
    while (scanf("%d", &a[al]) == 1 && a[al] != -1)
        al++;

    printf("Type elements of B separated by spaces(type '-1' to stop): ");
    while (scanf("%d", &b[bl]) == 1 && b[bl] != -1)
        bl++;

    sort(a, al);
    sort(b, bl);

    numberOfTimes(a, al, b, bl);

    return 0;
}
Type elements of A separated by spaces. Do not enter duplicates (type '-1' to stop): 3 2 1 -1
Type elements of B separated by spaces(type '-1' to stop): 1 3 2 3 3 2 1 -1
(1, 2) (2, 2) (3, 3)
