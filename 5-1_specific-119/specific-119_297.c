#include <stdio.h>

int main(int argc, const char * argv[]) {
    int histogram[10000];
    int i;
    while (1) {
        int *rectPtr = histogram;
        int size;
        scanf("%d", &size);
        if (size == 0) return 0;
        for (i = 0; i < size; ++i) {
            scanf("%d", rectPtr);
            rectPtr++;
        }
        printf("%d", 1);
        printf("\n");
    }
    return 0;
}
