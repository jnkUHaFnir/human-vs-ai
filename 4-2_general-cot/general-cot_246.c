#include <stdio.h>
#include <string.h>

int main() {
    int arr_int[1000];
    char arr_char[4000];

    memset(arr_int, 0, sizeof(arr_int)); // Efficient zero assignment using int
    memset(arr_char, 0, sizeof(arr_char)); // Less efficient zero assignment using char

    return 0;
}
