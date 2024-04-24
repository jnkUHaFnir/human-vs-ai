char **list = malloc((argc + 1) * sizeof(char*)); // Allocate argc+1 elements
if(list == NULL) {
    // Handle allocation failure
}

int i;
for(i = 0; i < argc; ++i) {
    list[i] = malloc(strlen(argv[i]) + 1);
    if(list[i] == NULL) {
        // Handle allocation failure
    }
    strcpy(list[i], argv[i]);
}
list[argc] = NULL; // Set the last element to NULL

execv(list[0], list);

// Free memory after execv if needed
for(i = 0; i <= argc; ++i) {
    free(list[i]);
}
free(list);
