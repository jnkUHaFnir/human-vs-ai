#include <stdio.h>
#include <stdlib.h>

struct x {
    int a;
    int b;
};

int main() {
    char input[100];
    struct x arr[5];

    printf("Enter input: ");
    fgets(input, 100, stdin); // read the input line

    int i = 0;
    char *token = strtok(input, "(, )");
    while (token != NULL) {
        arr[i / 2].a = atoi(token); // store first value in a
        token = strtok(NULL, ", "); // move to the next value
        arr[i / 2].b = atoi(token); // store second value in b
        token = strtok(NULL, "(, )"); // move to the next pair
        i += 2;
    }

    // Print the values stored in the array
    for (int j = 0; j < 5; j++) {
        printf("(%d, %d)\n", arr[j].a, arr[j].b);
    }

    return 0;
}
