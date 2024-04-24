file new_file(char* name, char* content) {
    file new_file;
    new_file.name = strdup(name); // Allocate memory and copy the name
    new_file.size = strlen(content); // Update the size
    new_file.content = strdup(content); // Allocate memory and copy the content
    return new_file;
}
void add_file(dir* folder, file* f) {
    folder->files[folder->index] = f;
    folder->index++;
}
file* find_file(dir* folder, char* name) {
    for (size_t i = 0; i < folder->index; i++) {
        if (strcmp(folder->files[i]->name, name) == 0) {
            return folder->files[i];
        }
    }
    return NULL; // Return NULL if file is not found
}
char* read(dir* folder, char* name) {
    file* f = find_file(folder, name);
    if (f != NULL) {
        return f->content;
    } else {
        return NULL;
    }
}
