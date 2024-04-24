unsigned char *src = NULL;
int length = (parameterArray[i].sizeInBits/8) + 1; 
unsigned char *tmp = (unsigned char*)malloc(length * sizeof(unsigned char)); 

memcpy(tmp, (char*)&parameterArray[i].valueU8, length); 
src = realloc(src, (strlen(src) + length + 1) * sizeof(unsigned char)); 
if(src == NULL) {
    perror("realloc");
    exit(EXIT_FAILURE);
}
strncat((char*)src, (char*)tmp, length); 
free(tmp); // free the temporary array
