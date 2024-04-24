unsigned char *src = NULL; // initialize it to NULL
int length = (parameterArray[i].sizeInBits/8) + 1;  // check how long array should be
unsigned char tmp[length]; // declare array

memcpy(tmp, (char*)&parameterArray[i].valueU8, length); // in this case copy char to array

// Use length, not strlen(tmp)
src = realloc(src, (src ? strlen(src) : 0) + length);

// use length, not strlen(tmp)
strncat(src, tmp, length); // merge
