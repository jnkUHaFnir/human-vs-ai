#include <stdio.h>

struct x {
    int a;
    int b;
};

int main() {
    char input[100]; // assuming a reasonable input size
    struct x arr[100]; // assuming a reasonable array size

    // Read the input line
    fgets(input, sizeof(input), stdin);

    int numRead = 0;
    int offset = 0;
    while (sscanf(input + offset, "(%d,%d)", &arr[numRead].a, &arr[numRead].b) == 2) {
        numRead++;
        offset += 8; // characters in "(%d,%d)"
    }

    // Print the values to check
    for (int i = 0; i < numRead; i++) {
        printf("(%d, %d)\n", arr[i].a, arr[i].b);
    }

    return 0;
}
