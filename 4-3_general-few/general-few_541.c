#include <stdio.h>

struct x {
    int a;
    int b;
};

int main() {
    // Input string
    char input[] = "((1828,299),(2729,2553),(2797,2929),(2200,1383),(2894,876))";

    // Array of struct x
    struct x arr[5];

    // Read input using sscanf
    int i = 0;
    const char* ptr = input;
    while (sscanf(ptr, "(%d,%d)", &arr[i].a, &arr[i].b) == 2) {
        i++;
        ptr += 10; // Move to the next tuple in the input
    }

    // Print out the values that were read
    for (i = 0; i < 5; i++) {
        printf("arr[%d].a = %d, arr[%d].b = %d\n", i, arr[i].a, i, arr[i].b);
    }

    return 0;
}
