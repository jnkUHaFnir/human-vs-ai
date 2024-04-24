unsigned char *src = NULL;
int length = (parameterArray[i].sizeInBits/8) + 1;
unsigned char tmp[length];

memcpy(tmp, (char*)&parameterArray[i].valueU8, length);

size_t src_length = src ? strlen(src) : 0; // get current length of src
src = realloc(src, src_length + strlen(tmp) + 1); // +1 for null terminator

if (src == NULL) {
    // handle error reallocating memory
    printf("Error reallocating memory\n");
    exit(1);
}

strncat(src, tmp, strlen(tmp));
