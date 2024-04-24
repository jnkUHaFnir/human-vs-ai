void new_file(dir* folder, char* name, char* content) {
    // Allocate memory for the file struct on the heap
    file* f = (file*)malloc(sizeof(file));

    // Allocate memory for the name and copy it
    f->name = (char*)malloc(strlen(name) + 1);
    strcpy(f->name, name);

    // Allocate memory for the content and copy it
    f->content = (char*)malloc(strlen(content) + 1);
    strcpy(f->content, content);

    // Set the size of the file
    f->size = strlen(content);

    // Add the file to the folder
    folder->files[folder->index] = f;
    folder->index++;
}
char* read(dir* folder, char* name) {
    file* f = find_file(folder, name);
    return (f == NULL) ? NULL : f->content;
}

file* find_file(dir* folder, char* name) {
    for (size_t i = 0; i < folder->index; i++) {
        file* f = folder->files[i];
        if (strcmp(f->name, name) == 0) {
            return f;
        }
    }
    return NULL;
}
