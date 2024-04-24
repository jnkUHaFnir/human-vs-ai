#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char *buffer;
    long file_size;

    fp = fopen("file.txt", "rb");    // open file in binary mode
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // get file size
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // allocate memory for buffer
    buffer = (char*) malloc(file_size + 1);

    // read file contents into buffer
    fread(buffer, file_size, 1, fp);
    buffer[file_size] = '\0';   // add null terminator to end of buffer

    // do something with buffer

    free(buffer);   // free allocated memory
    fclose(fp);     // close file

    return 0;
}
