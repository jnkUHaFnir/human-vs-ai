#include <stdlib.h>
#include <string.h>

void new(dir* folder, char* name, char* content) {
    file* f = (file*)malloc(sizeof(file)); // Allocate memory for file struct
    if (f == NULL) {
        // Handle allocation failure
        return;
    }

    f->name = strdup(name); // Allocate memory for name and copy it
    f->content = strdup(content); // Allocate memory for content and copy it
    f->size = strlen(content); // Calculate size

    folder->files[folder->index] = f;
    folder->index++;
}
