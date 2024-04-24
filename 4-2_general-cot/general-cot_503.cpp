#include <vector>

int main(int argc, char * argv[]) {
    const unsigned long long size = 1000000000;
    int * a = (int *)malloc(size * sizeof(int));
    int next_power = 1;
    for (int i = 0; i < size; i++) {
        a[i] = i;
        if (i == next_power - 1) {
            next_power *= 2;
            int *tmp = (int *)realloc(a, next_power * sizeof(int));
            if (tmp == nullptr) {
                // Handle realloc failure here
                free(a);
                return 1;
            }
            a = tmp;
        }
    }
    free(a);
    return 0;
}
