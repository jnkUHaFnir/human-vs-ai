int *ptr = malloc(n * sizeof(int));
int *ptr = malloc(n * sizeof(int));
if(ptr == NULL) {
    // Handle malloc failure
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
}
