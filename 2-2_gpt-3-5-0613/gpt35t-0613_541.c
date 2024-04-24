struct x {
    int a;
    int b;
};
struct x arr[5]; // assuming you want an array of size 5
for (int i = 0; i < 5; i++) {
    scanf(" (%d,%d)", &arr[i].a, &arr[i].b);
}
for (int i = 0; i < 5; i++) {
    printf("(%d,%d)\n", arr[i].a, arr[i].b);
}
#include <stdio.h>

struct x {
    int a;
    int b;
};

int main() {
    struct x arr[5];

    for (int i = 0; i < 5; i++) {
        scanf(" (%d,%d)", &arr[i].a, &arr[i].b);
    }

    for (int i = 0; i < 5; i++) {
        printf("(%d,%d)\n", arr[i].a, arr[i].b);
    }

    return 0;
}
