#include <stdio.h>

void fun1(int a[], int size) {
    if (size > 4) {
        a[4] = 1;
    } else {
        printf("Array size is too small to access index 4\n");
    }
}

int main() {
    int a[2] = {1, 2};
    int size = sizeof(a) / sizeof(a[0]); // Calculate the size of array 'a'
    
    fun1(a, size);
    
    printf("%d", a[4]);  // Will not be accessed in this corrected version

    return 0;
}
