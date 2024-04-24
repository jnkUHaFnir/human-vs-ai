#include <stdlib.h>
#include <string.h>

typedef struct {
    char* content; // Now a pointer to a single string
    char* name;
    size_t size;
} file;

typedef struct {
    file* files[256];
    char* name;
    size_t index; // Initialized to 0 when struct is created
} dir;

// Function to dynamically create a new file struct and add it to the directory
void new(dir* folder, char* name, char* content) {
    // Dynamically allocate memory for the new file
    file* f = malloc(sizeof(file));
    if (!f) return; // Check for allocation failure
    
    // Dynamically allocate memory and copy the name and content strings
    f->name = strdup(name);
    f->content = strdup(content);
    f->size = strlen(content); // Assuming this is what you intended for size. Modify as needed.
    
    // Add the file pointer to the directory
    folder->files[folder->index] = f;
    folder->index++;
}

// Don't forget to eventually free the memory you allocated!
void cleanup_directory(dir* folder) {
    for (size_t i = 0; i < folder->index; i++) {
        // Free the strings and file structs you dynamically allocated
        free(folder->files[i]->name);
        free(folder->files[i]->content);
        free(folder->files[i]);
    }
}

// Example main function
int main() {
    dir myDirectory = {0}; // Initialize an empty directory
    new(&myDirectory, "testfile", "Hello, World!");

    // Don't forget to clean up after you're done
    cleanup_directory(&myDirectory);
    return 0;
}
