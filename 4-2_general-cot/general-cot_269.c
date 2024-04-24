char **list_pointers = malloc((argc + 1) * sizeof(char*)); // Allocate memory for an extra pointer
int i;
for (i = 0; i < argc; ++i) {
    list_pointers[i] = list[i];
}
list_pointers[argc] = NULL; // Ensure the last element is NULL as required by execv

execv(list_pointers[0], list_pointers);

// Free memory for list_pointers after execv has been called
free(list_pointers);
