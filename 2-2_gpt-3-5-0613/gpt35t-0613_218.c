unsigned char *src = NULL; // Initialize src to NULL
size_t srcLength = 0; // Track the length of src
int tmpLength = length + 1; // Include space for the null terminator

src = realloc(src, srcLength + tmpLength); // Allocate space for src plus tmp
if (src == NULL) {
    // Handle realloc failure
    // ...
}

strncat(src, tmp, tmpLength); // Merge tmp into src

// Update srcLength to include the length of tmp
srcLength += tmpLength;
