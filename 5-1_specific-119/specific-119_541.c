#include <stdio.h>

struct x {
    int a;
    int b;
};

int main() {
    char input[100];
    struct x arr[5];
    int i = 0;

    fgets(input, 100, stdin); // Read input using fgets to avoid buffer overflow

    // Parse the input using sscanf
    int a, b;
    const char* ptr = input;
    while (sscanf(ptr, "(%d,%d),%*c", &a, &b) == 2) {
        arr[i].a = a;
        arr[i].b = b;
        i++;
        ptr += 12; // Move to the next pair in the input
    }

    // Print the values to verify
    for (int j = 0; j < 5; j++) {
        printf("arr[%d]: a=%d, b=%d\n", j, arr[j].a, arr[j].b);
    }

    return 0;
}
