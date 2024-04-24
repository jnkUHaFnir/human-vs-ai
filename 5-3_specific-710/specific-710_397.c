file new_file(char* name, char* content) { 
    file f;
    f.name = name;
    f.content = strdup(content); // Make a copy of the content
    f.size = strlen(content); // Set the size

    return f;
}
void add_file(dir* folder, file* f) {
    folder->files[folder->index] = f;
    folder->index++;
}
char* read(dir* folder, char* name) {
    file f = find_file(folder, name);
    char* content_copy = strdup(f.content); // Make a copy of the content
    return content_copy;
}
file* find_file(dir* folder, char* name) {
    for (size_t i = 0; i < folder->index; i++) {
        file* f = folder->files[i];
        if (strcmp(f->name, name) == 0) { // Use proper string comparison here
            return f;
        }
    }
    return NULL; // Return NULL if file not found
}
