#include <stdio.h>

void sort(int a[], int n) { // Pass length of the array as an argument
    int i, j, t;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

// Pass the lengths of the arrays as arguments
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
    printf("\n"); // Add a newline at the end
}

int main() { // main should return an int
    int maxarraylen = 1000, i = 0;
    int a[maxarraylen];
    int b[maxarraylen];
    int lengthA = 0, lengthB = 0; // To keep track of how many elements are actually in both arrays

    printf("Type elements of A separated by spaces. Do not enter duplicates (type 'end' to stop): ");
    while (scanf("%d", &a[lengthA]) == 1)
        lengthA++;
    // Consume the rest of the line including 'end'
    scanf("%*200[^\n]"); // Assuming a max of 200 characters to skip

    printf("Type elements of B separated by spaces (type 'end' to stop): ");
    while (scanf("%d", &b[lengthB]) == 1)
        lengthB++;
    scanf("%*200[^\n]"); // Assuming a max of 200 characters to skip again

    sort(a, lengthA); // Pass the actual number of elements to sort
    sort(b, lengthB);

    numberOfTimes(a, lengthA, b, lengthB); // Pass lengths here too

    return 0;
}
