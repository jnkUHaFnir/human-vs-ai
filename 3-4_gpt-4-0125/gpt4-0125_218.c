int srcLength = 0; // Keep track of the length of src
unsigned char *src = NULL; // Ensure src is initially NULL

for (/* your loop conditions here */) {
    int length = (parameterArray[i].sizeInBits / 8) + 1;
    unsigned char tmp[length];
    memcpy(tmp, &parameterArray[i].valueU8, length);

    src = realloc(src, srcLength + length); // Allocate enough space
    if (src == NULL) {
        // Handle allocation failure; perhaps by breaking or returning
    }

    memcpy(src + srcLength, tmp, length); // Append tmp to src
    srcLength += length; // Update src length
}

// Make sure to free "src" when you're done using it to avoid memory leaks
