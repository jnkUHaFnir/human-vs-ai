#include <gmp.h>

void print_array(unsigned char* arr, size_t size) {
    mpz_t num;
    mpz_init(num);
    for (size_t i = size-1; i < size; i--) {
        mpz_mul_ui(num, num, 256);
        mpz_add_ui(num, num, arr[i]);
    }
    char* str = mpz_get_str(NULL, 10, num);
    printf("%s\n", str);
    free(str);
    mpz_clear(num);
}

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    print_array(n, 3);
    // output: 197121
    return 0;
}
void print_array(unsigned char* arr, size_t size) {
    unsigned char temp[size];
    char str[40]; // enough for 128-bit integers
    memset(temp, 0, size); // initialize temp to 0
    temp[size-1] = arr[size-1];
    for (size_t i = size-2; i < size; i--) {
        for (size_t j = i; j < size-1; j++) { // multiply temp by 256
            temp[j] *= 256;
            temp[j] += temp[j+1]/10;
            temp[j+1] %= 10;
        }
        temp[size-1] = arr[i];
    }
    // convert temp to base 10 string
    int len = sprintf(str, "%d", temp[0]);
    for (size_t i = 1; i < size; i++) {
        len += sprintf(str + len, "%02d", temp[i]);
    }
    printf("%s\n", str);
}
