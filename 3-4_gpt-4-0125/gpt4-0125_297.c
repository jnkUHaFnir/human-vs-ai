#include <stdio.h>

int main() {
    int histogram[10000];
    int i;
    while (1) {
        int *rectPtr = histogram;
        int size;
        if (scanf("%d", &size) != 1 || size <= 0 || size > 10000) {
            fprintf(stderr, "Invalid size.\n");
            return -1;
        }
        for (i = 0; i < size; ++i) {
            if (scanf("%d", rectPtr++) != 1) {
                fprintf(stderr, "Failed to read number.\n");
                while ((getchar()) != '\n'); // Clear the buffer
                break;
            }
        }
        printf("%d\n", 1);
    }
    return 0;
}
