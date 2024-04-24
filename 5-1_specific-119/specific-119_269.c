char **list = malloc((argc + 1) * sizeof(char*)); // Allocate space for an extra NULL pointer
int i;
for (i = 0; i < argc; ++i) {
    list[i] = malloc(strlen(argv[i]) + 1);
    strcpy(list[i], argv[i]);
}
list[argc] = NULL; // Set the last pointer to NULL to mark the end of the list

execv(list[0], list);

// Free the memory after execv if needed
for (i = 0; i < argc; ++i) {
    free(list[i]);
}
free(list);
