char* data = ...; // received char array
int data_len = ...; // length of char array

char* ptr = &data[8]; // start at byte 8
while (ptr < &data[data_len]) { // loop until end of char array
    char* end = strchr(ptr, '\0'); // find next NUL char
    if (end == NULL) {
        // handle error: expected another string but not enough NUL chars
        break;
    }
    int len = end - ptr; // length of substring
    char* str = (char*) malloc(len + 1); // allocate buffer for string
    memcpy(str, ptr, len); // copy substring to new buffer
    str[len] = '\0'; // null-terminate the string
    // use the string...
    printf("%s\n", str);
    // free the buffer
    free(str);
    // update pointer to start of next substring
    ptr = end + 1;
}
