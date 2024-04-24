void new(dir* folder, char* name, char* content) {
    file f;
    f.name = name;
    f.content = malloc(strlen(content) + 1); // Allocate memory for content
    strcpy(f.content, content);  // Copy content into allocated memory

    folder->files[folder->index] = f;
    folder->index++;
}
void add_file(dir* folder, file f) {
    folder->files[folder->dirnum] = f;
    folder->dirnum++;
}
