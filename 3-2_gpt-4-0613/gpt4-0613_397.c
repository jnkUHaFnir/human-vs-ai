void new(dir* folder, char* name, char* content) { 
    // allocate memory for a new file struct
    file *f = malloc(sizeof(file));

    // Allocate memory for the name and the content
    f->name = malloc(strlen(name) + 1);
    strcpy(f->name, name);

    f->content = malloc(strlen(content) + 1);
    strcpy(f->content, content);

    // add the new file to the directory
    folder -> files[folder -> index] = f;
    folder -> index++;
}
