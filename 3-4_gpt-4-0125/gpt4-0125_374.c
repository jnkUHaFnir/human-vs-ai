for (i = 1; scanf("%d", &c) == 1; i++) {
    pSet = (int*) realloc(pSet, sizeof(int) * i); // This should be * i because we have already incremented i.
    if (pSet == NULL) {
        // Assuming FAIL is defined somewhere. You might want to return a specific error code or handle the error appropriately.
        return FAIL; 
    }
    pSet[i - 1] = c;  // Since i is already incremented, use i - 1 to correctly index into the array.
    printf("%d ", c);
}
if (pSet == NULL) {
    // Handle memory allocation failure, possibly by returning an error code or exiting.
    return FAIL;
}
