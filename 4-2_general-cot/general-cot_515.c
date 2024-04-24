#include <stdio.h>
#include <stdlib.h>

void openFile(FILE** file, char* filename) {
    int SIZE = 10;
    char* data = NULL;
    char c;
    int n = 0;
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    if (!((*file) = fopen(filename, "r"))) {
        perror("Error");
        return;
    }
    
    // Allocate initial memory for data
    data = (char*)malloc(SIZE * sizeof(char));
    if (data == NULL) {
        perror("malloc");
        fclose(*file);
        return;
    }
    
    while (fscanf(*file, " %c", &c) != EOF) {
        if (n < SIZE) {
            data[n++] = c;
        } else {
            // Increase the size of data if n exceeds SIZE
            SIZE *= 2;
            char* temp = (char*)realloc(data, SIZE * sizeof(char));
            if (temp == NULL) {
                perror("realloc");
                free(data);
                fclose(*file);
                return;
            }
            data = temp;
            data[n++] = c;
        }
    }

    // Null-terminate the string
    data[n] = '\0';

    // Print the content read from the file
    printf("File content:\n%s\n", data);
    
    free(data);
    fclose(*file);
}

int main() {
    FILE* file;
    char filename[100];
    
    openFile(&file, filename);
    
    return 0;
}
