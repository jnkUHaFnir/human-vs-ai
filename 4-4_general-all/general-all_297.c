#include <stdio.h>

int main(int argc, const char * argv[]) {
    int histogram[10000];
    int i;
    
    while (1) {
        int *rectPtr = histogram;
        int size;
        scanf("%d", &size);
        if (!size) return 0;
        
        for (i = 0; i < size; ++i) {
            if (rectPtr >= histogram + 10000) {
                printf("Exceeded array size.\n");
                return 1;
            }
            scanf("%d", rectPtr);
            rectPtr++;
        }
        
        printf("%d\n", 1);
    }
    return 0;
}
