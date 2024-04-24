#include <stdio.h>

void fun1(int a[], int size) {
    if (size > 4) {
        a[4] = 1;
    } else {
        printf("Array size is too small for accessing index 4\n");
    }
}

int main() {
    int a[2] = {1, 2};
    int size = sizeof(a) / sizeof(a[0]); // Calculate the size of the array
    fun1(a, size);
    printf("%d", a[4]); // Output 1
    return 0;
}
