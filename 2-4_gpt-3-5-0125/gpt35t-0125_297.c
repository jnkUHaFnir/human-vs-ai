int main(int argc, const char * argv[]) {
    int histogram[10000];
    int i;
    while (1) {
        int *rectPtr = histogram;
        int size;
        scanf("%d", &size);
        if (!size) return 0;
        for (i = 0; i < size; ++i) {
            scanf("%d", rectPtr);
            rectPtr++;
        }
        rectPtr = histogram; // Reset the pointer back to the start
        printf("%d", 1);
        printf("\n");
    }
    return 0;
}
