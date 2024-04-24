#include <stdio.h>

struct x {
    int a;
    int b;
};

int main() {
    const int arr_size = 5;
    struct x arr[arr_size];

    for (int i = 0; i < arr_size; i++) {
        scanf(" (%d,%d)", &arr[i].a, &arr[i].b);
    }

    // Printing the values
    for (int i = 0; i < arr_size; i++) {
        printf("a: %d, b: %d\n", arr[i].a, arr[i].b);
    }

    return 0;
}
