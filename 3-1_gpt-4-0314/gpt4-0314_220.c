int n, m;
scanf("%d %d", &m, &n);
int *arr = malloc(sizeof(int) * n * m);

for (int i = 0; i < m * n; scanf("%d", arr + i), i++);

printf("Entered numbers:\n");
for (int i = 0; i < m * n; i++) {
    printf("%d ", arr[i]);
}
printf("\n");

free(arr); // Don't forget to free the memory you allocated
int *arr = malloc(sizeof(int) * n * m);
if (arr == NULL) {
    perror("Error allocating memory");
    return -1;
}
for (int i = 0; i < m * n; i++) {
    scanf("%d", arr + i);
}
