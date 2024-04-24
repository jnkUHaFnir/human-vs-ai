#include <stdio.h>

void sort(int *a, int l) {
    int i, j, t;
    for (i = 0; i < l-1; i++) {
        for (j = 0; j < l-1-i; j++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void numberOfTimes(int *a, int al, int *b, int bl) {
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

int main() {
    int maxarraylen = 1000, i = 0;
    int a[maxarraylen], al = 0;
    int b[maxarraylen], bl = 0;

    printf("Type elements of A separated by spaces. Do not enter duplicates (type 'end' to stop):\n");
    while (scanf("%d", &a[al]) == 1)
        al++;
    scanf("%*s");

    printf("Type elements of B separated by spaces (type 'end' to stop):\n");
    while (scanf("%d", &b[bl]) == 1)
        bl++;
    scanf("%*s");

    sort(a, al);
    sort(b, bl);

    numberOfTimes(a, al, b, bl);

    return 0;
}
