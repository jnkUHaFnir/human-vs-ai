char **list_pointers = malloc((argc+1)*sizeof(char*));
int i=0;
for(i=0; i<argc; ++i){
    list_pointers[i] = list[i];
}
list_pointers[argc] = NULL; // Null-terminate the list of pointers

execv(list_pointers[0], list_pointers);
