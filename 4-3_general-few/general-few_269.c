char **list_pointers = malloc((argc + 1) * sizeof(char*)); // Need an extra NULL pointer at the end
if (list_pointers) {
    for (int i = 0; i < argc; ++i) {
        list_pointers[i] = list[i];
    }
    list_pointers[argc] = NULL; // Set the last element to NULL as required by execv

    execv(list_pointers[0], list_pointers);

    // Free the memory allocated for list_pointers after execv if needed
    free(list_pointers);
} else {
    // Handle allocation failure
}
