#include <stdio.h>
#include <stdlib.h>

struct x{
    int a;
    int b;
};

int main() {
    char input[100]; // Assuming input is less than 100 characters
    struct x arr[5]; // Assuming you have 5 elements in the input

    fgets(input, 100, stdin); // Read the whole line including spaces

    int values_read = sscanf(input, "((%d,%d),(%d,%d),(%d,%d),(%d,%d),(%d,%d))",
                            &arr[0].a, &arr[0].b, &arr[1].a, &arr[1].b, &arr[2].a, &arr[2].b,
                            &arr[3].a, &arr[3].b, &arr[4].a, &arr[4].b);

    if (values_read != 10) {
        printf("Invalid input format\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("Element %d: a=%d, b=%d\n", i, arr[i].a, arr[i].b);
    }

    return 0;
}
