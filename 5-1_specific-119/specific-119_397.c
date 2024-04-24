void new(dir* folder, char* name, char* content) {
    file* f = (file*)malloc(sizeof(file)); // Allocate memory for a new file
    if (f == NULL) {
        // Handle memory allocation failure
        return;
    }
    
    f->name = strdup(name);
    f->content = strdup(content);
    
    folder->files[folder->index] = f;
    folder->index++;
}
char* read(dir* folder, char* name) {
    for (size_t i = 0; i < folder->index; i++) {
        if (strcmp(folder->files[i]->name, name) == 0) {
            return folder->files[i]->content;
        }
    }
    
    return NULL; // File not found
}
void free_file(file* f) {
    free(f->name);
    free(f->content);
    free(f);
}
