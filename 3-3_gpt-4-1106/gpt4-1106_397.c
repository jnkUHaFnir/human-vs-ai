void new_file(dir* folder, char* name, char* content) {
    file* f = malloc(sizeof(file));
    if (!f) {
        // Handle malloc failure
        return;
    }
    f->name = strdup(name); // strdup allocates memory for a copy of the string
    f->content = malloc(strlen(content) + 1);
    strcpy(f->content, content); // Copy the provided content into the newly allocated space
    f->size = strlen(content);
    
    folder->files[folder->index] = f;
    folder->index++;
}

file* find_file(dir* folder, char* name) {
    for (size_t i = 0; i < folder->index; i++) {
        if (strcmp(folder->files[i]->name, name) == 0) {
            return folder->files[i];
        }
    }
    return NULL; // File not found
}

char* read_file(dir* folder, char* name) {
    file* f = find_file(folder, name);
    if (f) {
        return f->content;
    }
    return NULL; // File not found or error
}
