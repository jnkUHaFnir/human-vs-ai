#include <stdio.h>

void sort(int* a, int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void numberOfTimes(int* a, int al, int* b, int bl) {
    int i, p, c;

    for (i = 0; i < al; i++) {
        c = 0; // Reset count for each element in a
        for (p = 0; p < bl; p++) {
            if (a[i] == b[p]) {
                c++; // Increment count when a match is found
            }
        }
        printf("(%d, %d) ", a[i], c);
    }
}

int main() { // int main() is the correct signature
    int a[] = {3, 2, 1};
    int b[] = {1, 3, 2, 3, 3, 2, 1};
    int al = sizeof(a) / sizeof(a[0]); //Correctly calculating the size here at compile time because we know the array size
    int bl = sizeof(b) / sizeof(b[0]); //Correctly calculating the size here at compile time because we know the array size

    sort(a, al);
    sort(b, bl);

    numberOfTimes(a, al, b, bl);

    return 0;
}
