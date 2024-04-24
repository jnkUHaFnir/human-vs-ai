#include <stdio.h>

void sort(int a[]) {
    int i, j, l, t; 
    l = sizeof(a) / sizeof(a[0]);

    for (i = 0; i < l + 1; i++) {
        for (j = 0; j < (l - i); j++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void numberOfTimes(int a[], int b[]) {
    int al = sizeof(a) / sizeof(a[0]);
    int bl = sizeof(b) / sizeof(b[0]);
    int i, p, c = 0;

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

void main() {
    int maxarraylen = 1000, i = 0;
    int a[maxarraylen];
    int b[maxarraylen];

    printf("Type elements of A separated by spaces. Do not enter duplicates (type 'end' to stop): ");
    while (scanf("%d", &a[i]) == 1)
        i++;
    scanf("%*s");
    
    i = 0;

    printf("Type elements of B separated by spaces(type 'end' to stop): ");
    while (scanf("%d", &b[i]) == 1)
        i++;
    scanf("%*s");

    sort(a);
    sort(b);

    numberOfTimes(a, b);
}
