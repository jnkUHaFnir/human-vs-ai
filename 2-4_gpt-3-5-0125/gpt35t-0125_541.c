#include <stdio.h>

struct x {
    int a;
    int b;
};

int main() {
    struct x arr[5];
    
    for (int i = 0; i < 5; i++) {
        scanf("((%d,%d),(%d,%d),(%d,%d),(%d,%d),(%d,%d))",
              &arr[i].a, &arr[i].b,
              &arr[i].a, &arr[i].b,
              &arr[i].a, &arr[i].b,
              &arr[i].a, &arr[i].b,
              &arr[i].a, &arr[i].b);
    }

    // Print the values stored in the array of structs
    for (int i = 0; i < 5; i++) {
        printf("arr[%d].a = %d, arr[%d].b = %d\n", i, arr[i].a, i, arr[i].b);
    }

    return 0;
}
