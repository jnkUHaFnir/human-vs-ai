#define INITIAL_BUFF_SIZE 1024

char* readline(FILE* fp) {
    int ch;
    size_t buff_len = INITIAL_BUFF_SIZE;
    char* buffer = malloc(buff_len);
    size_t i = 0;

    if(buffer == NULL){
        return NULL;
    }

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) { 
        if (i == buff_len - 1) {  // the additional room for '\0'
            buff_len *= 2;
            char* temp = realloc(buffer, buff_len);
            if (temp == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }
        buffer[i++] = ch;
    }

    if (i == 0 && ch == EOF) { // buffer is "" and EOF reached, it indicates end of file
        free(buffer);
        return NULL;
    }

    buffer[i] = '\0'; // null terminate
    return buffer;
}
