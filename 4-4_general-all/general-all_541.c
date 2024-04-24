#include <stdio.h>

struct x {
    int a;
    int b;
};

int main() {
    struct x arr[5]; // Array of structs

    for (int i = 0; i < 5; i++) {
        if (scanf("((%d,%d),(%d,%d),(%d,%d),(%d,%d),(%d,%d))",
                   &arr[i].a, &arr[i].b,
                   &arr[i].a, &arr[i].b,
                   &arr[i].a, &arr[i].b,
                   &arr[i].a, &arr[i].b,
                   &arr[i].a, &arr[i].b) != 10) {
            fprintf(stderr, "Invalid input format\n");
            return 1;
        }
    }

    // Printing the values to verify
    for (int i = 0; i < 5; i++) {
        printf("Array element %d: a=%d, b=%d\n", i, arr[i].a, arr[i].b);
    }

    return 0;
}
