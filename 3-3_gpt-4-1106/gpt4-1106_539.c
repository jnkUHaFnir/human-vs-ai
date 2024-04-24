#include <stdio.h>

void sort(int a[], int size) {
    int i, j, t;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
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
                c++;
            }
        }   
        printf("(%d, %d) ", a[i], c);
    }
    printf("\n");
}

int main() { // Note: main should return an int
    int maxarraylen = 1000, i = 0, al = 0, bl = 0;
    int a[maxarraylen];
    int b[maxarraylen];

    printf("Type elements of A separated by spaces. Do not enter duplicates (type 'end' to stop): ");
    while (scanf("%d", &a[al++]) == 1) {
        // no body needed
    }
    al--; // decrement to remove the 'end' increment
    scanf("%*s"); // skip the 'end' word

    printf("Type elements of B separated by spaces(type 'end' to stop): ");
    while (scanf("%d", &b[bl++]) == 1) {
        // no body needed
    }
    bl--; // decrement to remove the 'end' increment
    scanf("%*s"); // skip the 'end' word

    sort(a, al);
    sort(b, bl);

    numberOfTimes(a, al, b, bl);

    return 0; // main should return a value
}
