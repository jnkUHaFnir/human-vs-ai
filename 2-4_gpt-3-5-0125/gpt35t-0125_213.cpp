int main() {
    FILE* file = fopen("files.txt", "r");

    int num;
    fscanf(file, "%d", &num);

    int* p = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        fscanf(file, "%d", &p[i]);
    }

    for (int i = 0; i < num; i++) {
        printf("%d ", p[i]);
    }
    printf("\n%d\n", num);

    free(p);
    fclose(file);

    return 0;
}
