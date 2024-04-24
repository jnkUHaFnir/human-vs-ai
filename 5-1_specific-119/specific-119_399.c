char buffer[100];
fgets(buffer, sizeof(buffer), stdin);
int *ptr = (int*)malloc(sizeof(int));
if (ptr == NULL) {
    // Handle allocation failure
    printf("Memory allocation failed!\n");
} else {
    // Proceed with using the allocated memory
    *ptr = 42;
}
