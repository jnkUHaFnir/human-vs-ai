#include <stdio.h>
#include <stdlib.h>

void openFile(FILE** file, char* filename) {
    int SIZE = 10;
    char *data, *data2;
    int n = 0;
    int c; // Use int to store the return value of fgetc (not char)
    printf("filename: ");
    scanf("%s", filename);
    if (!((*file) = fopen(filename, "r"))) {
        perror("Error:");
    } else {
        data = (char *)malloc(SIZE * sizeof(char));
        if (data == NULL) {
            perror("malloc:");
            return; // Return after malloc failure
        }
        while ((c = fgetc(*file)) != EOF) { // Use fgetc to read characters
            if (n >= SIZE - 1) { // Check if resize is needed, save space for null terminator
                SIZE *= 2; // Double the size
                data2 = (char *)realloc(data, SIZE * sizeof(char));
                if (data2 == NULL) {
                    free(data);
                    perror("realloc:");
                    return; // Return after realloc failure
                }
                data = data2;
            }
            data[n++] = (char)c; // Cast to char before storing
        }
        data[n] = '\0'; // Null-terminate the string
        printf("Contents: %s\n", data); // Print the read contents
        free(data); // Free the allocated memory
    }
}

int main() {
    FILE *file;
    char filename[256]; // Allocate space for filename
    openFile(&file, filename);
    if (file) {
        fclose(file); // Don't forget to close the file
    }
    return 0;
}
