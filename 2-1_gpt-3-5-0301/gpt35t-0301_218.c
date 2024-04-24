unsigned char *src = NULL; // initialize to NULL
int length = (parameterArray[i].sizeInBits/8) + 1;
unsigned char tmp[length];

memcpy(tmp, (char*)&parameterArray[i].valueU8, length);

src = realloc(src, strlen((char*)src) + length + 1); // add 1 for null terminator
if (src == NULL) {
    // handle error, e.g. print error message and exit program
    fprintf(stderr, "Error: failed to reallocate memory\n");
    exit(EXIT_FAILURE);
}

strncat(src, tmp, length);
src[strlen((char*)src)] = '\0'; // add null terminator
