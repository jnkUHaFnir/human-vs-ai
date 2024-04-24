#include <stdio.h>

void sort(int a[], int length) {
    int i, j, t; 

    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
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
}

int main() {
    int maxarraylen = 1000, i;
    int a[maxarraylen];
    int b[maxarraylen];

    printf("Type elements of A separated by spaces. Do not enter duplicates (type 'end' to stop): ");
    while (scanf("%d", &a[i]) == 1)
        i++;
    scanf("%*s");
    i = 0;

    printf("Type elements of B separated by spaces (type 'end' to stop): ");
    while (scanf("%d", &b[i]) == 1)
        i++;
    scanf("%*s");

    int al = i;
    int bl = i;

    sort(a, al);
    sort(b, bl);

    numberOfTimes(a, al, b, bl);

    return 0;
}
