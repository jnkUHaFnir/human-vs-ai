file* f = malloc(sizeof(file));
// Initialize the fields of the 'f' struct
free(f);
f.content = malloc(strlen(content) + 1); // +1 for terminating null character
strcpy(f.content, content);
free(f.content);
void add_file(dir* folder, file* f) {
    folder->files[folder->index] = f;
    folder->index++;
}
char* read(dir* folder, char* name) {
    file* f = find_file(folder, name);
    if (f == NULL) {
        return NULL; // File not found
    }
    char* content_copy = malloc(strlen(f->content) + 1);
    strcpy(content_copy, f->content);
    return content_copy;
}
if (strcmp(f.name, name) == 0) {
    return f;
}
