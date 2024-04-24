// Creates a new array with the current size on the heap.
float* fileArr = (float*)malloc(currentSz * sizeof(float));
if (fileArr == NULL) {
    // Handle allocation failure
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
}

// Your sorting and timing logic here

// Free the allocated memory when done
free(fileArr);
