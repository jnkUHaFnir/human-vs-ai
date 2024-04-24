#include <stdio.h>

struct x {
    int a;
    int b;
};

int main() {
    struct x arr[5]; // Assuming you know there are 5 elements to read
    int i;

    // Reading 5 pairs of integers from the input
    for (i = 0; i < 5; i++) {
        // Reading the input in the format of "(int,int)"
        scanf(" (%d,%d)", &arr[i].a, &arr[i].b); 
    }

    // Printing out the values to check
    for (i = 0; i < 5; i++) {
        printf("(%d,%d)\n", arr[i].a, arr[i].b);
    }

    return 0;
}
