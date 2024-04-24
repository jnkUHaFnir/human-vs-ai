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

void numberOfTimes(int a[], int alen, int b[], int blen) {
    int i, p, c;

    for (i = 0; i < alen; i++) {
        c = 0; // Reset counter for each element of a
        for (p = 0; p < blen; p++) {
            if (a[i] == b[p]) {
                c++;
            }
        }   
        printf("(%d, %d) ", a[i], c); // Print the count for the current element of a
    }
}

int main() {
    int maxarraylen = 1000, i = 0, j = 0;
    int a[maxarraylen];
    int b[maxarraylen];

    printf("Type elements of A separated by spaces. Do not enter duplicates (type 'end' to stop): ");
    while (scanf("%d", &a[i]) == 1)
        i++;
    i = 0;

    printf("Type elements of B separated by spaces (type 'end' to stop): ");
    while (scanf("%d", &b[j]) == 1)
        j++;

    sort(a, i);
    sort(b, j);

    numberOfTimes(a, i, b, j);

    return 0;
}
