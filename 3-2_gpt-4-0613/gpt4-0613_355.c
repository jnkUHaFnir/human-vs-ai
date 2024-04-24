
Now you just need to open your file and call this function:

```C
int main() {
    FILE* file = fopen("files.txt", "r");
    int* array;
    int size;
    readSpecificLine(file, 2, &array, &size);

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    free(array);
    fclose(file);

    return 0;
}
