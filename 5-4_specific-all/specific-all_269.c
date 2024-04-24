char **list = malloc(argc * sizeof(char*));
int i;
for(i = 0; i < argc; ++i) {
    list[i] = malloc(strlen(argv[i]) + 1);
    strcpy(list[i], argv[i]);
}

char **list_pointers = malloc((argc + 1) * sizeof(char*)); // Extra space for NULL terminator
for(i = 0; i < argc; ++i) {
    list_pointers[i] = list[i];
}
list_pointers[argc] = NULL; // Null-terminate the list

execv(list_pointers[0], list_pointers);

// Free the memory allocated for list and list_pointers after execv call
for(i = 0; i < argc; ++i) {
    free(list[i]);
}
free(list);
free(list_pointers);
