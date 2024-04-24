#include <stdio.h>

int main(int argc, const char * argv[]) {
    int histogram[10000];
    int i;
    while (1) {
        int *rectPtr = histogram;
        int size;
        if(scanf("%d", &size) != 1) {
            // Handle invalid input or end of input
            return 0;
        }
        if (size == 0) return 0;
        for (i = 0; i < size; ++i) {
            if (scanf("%d", rectPtr) != 1) {
                // Handle invalid input
                return 1;
            }
            rectPtr++;
        }
        printf("%d \n", 1);
    }
    return 0;
}
