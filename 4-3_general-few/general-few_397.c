void new(dir* folder, char* name, char* content) { 
    file* f = malloc(sizeof(file)); // Allocate memory for the new file
    if (f == NULL) {
        // Handle memory allocation error
        return;
    }
    
    f->name = malloc(strlen(name) + 1); // Allocate memory for the name string
    if (f->name == NULL) {
        // Handle memory allocation error
        free(f); // Clean up allocated memory
        return;
    }
    strcpy(f->name, name); // Copy the name string
    
    f->content = malloc(strlen(content) + 1); // Allocate memory for the content string
    if (f->content == NULL) {
        // Handle memory allocation error
        free(f->name); // Clean up allocated memory
        free(f); // Clean up allocated memory
        return;
    }
    strcpy(f->content, content); // Copy the content string
    
    folder->files[folder->index] = f;
    folder->index++;
}
