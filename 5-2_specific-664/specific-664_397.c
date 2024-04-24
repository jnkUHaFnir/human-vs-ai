void new(dir* folder, char* name, char* content) {
    file* f = (file*)malloc(sizeof(file)); // Allocate memory dynamically
    f->name = name;
    f->content = content;
    folder->files[folder->index] = f;
    folder->index++;
}
