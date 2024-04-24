file* new_file(char* name, char* content) {
    file* new = (file*)malloc(sizeof(file));
    new->name = name;
    new->content = content;
    new->size = strlen(content); // You can use strlen to get the size of the content
    return new;
}
void new(char* name, char* content, dir* folder) {
    file* new = new_file(name, content);
    add_file(folder, new);
}
