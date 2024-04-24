unsigned char *src = NULL;
size_t totalLength = 0; // track the total length of the combined string

int length = (parameterArray[i].sizeInBits / 8) + 1;
unsigned char tmp[length];
memcpy(tmp, (char*)&parameterArray[i].valueU8, length);

// Reallocate space for the total string, considering the null terminator
src = realloc(src, totalLength + length + 1);

if (src == NULL) {
    // Handle realloc failure
    // Optionally free tmp if necessary
    printf("Memory reallocation failed.\n");
} else {
    // Copy tmp to src
    memcpy(src + totalLength, tmp, length);

    // Update totalLength
    totalLength += length;

    // Null-terminate the string
    src[totalLength] = '\0';
}

// Don't forget to free the dynamically allocated memory when done
// free(src);
