#include <stdlib.h>
#include <string.h>

typedef struct {
    char* content; // Store text in the file
    char* name;     // Filename
    size_t size;    // Included from stddef.h - set by the function
} file;

typedef struct {
    file* files[256]; // The files in the directory
    char* name;       // The directory name
    size_t index;     // The index of the next file - basically the length of the files array - starts at 0
} dir;

void new_file(dir* folder, char* name, char* content) {
    file* f = (file*)malloc(sizeof(file));
    f->name = strdup(name); // Copy the name
    f->content = strdup(content); // Copy the content
    folder->files[folder->index] = f;
    folder->index++;
}

char* read(dir* folder, char* name) {
    for (size_t i = 0; i < folder->index; i++) {
        if (strcmp(folder->files[i]->name, name) == 0) {
            return strdup(folder->files[i]->content); // Return a copy of the content
        }
    }
    return NULL; // File not found
}

int main() {
    // Example usage
    dir root;
    root.index = 0;

    new_file(&root, "hi", "file");

    char* file_content = read(&root, "hi");
    if (file_content != NULL) {
        // Print or use file_content as needed
        printf("Content of 'hi' file: %s\n", file_content);
        free(file_content); // Free the copy of content returned by read function
    }

    return 0;
}
