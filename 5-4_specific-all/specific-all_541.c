#include <stdio.h>

struct x {
    int a;
    int b;
};

int main() {
    struct x arr[5];
    int i;

    for (i = 0; i < 5; i++) {
        scanf("(%d,%d)", &arr[i].a, &arr[i].b);
    }

    // Print the values to check
    for (i = 0; i < 5; i++) {
        printf("(%d, %d)\n", arr[i].a, arr[i].b);
    }

    return 0;
}
