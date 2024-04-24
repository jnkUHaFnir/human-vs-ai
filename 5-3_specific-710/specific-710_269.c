char **list = malloc(argc * sizeof(char*));
if (list == NULL) {
    // Handle malloc failure
    exit(EXIT_FAILURE);
}

int i;
for (i = 0; i < argc; ++i) {
    list[i] = malloc(strlen(argv[i]) + 1);
    if (list[i] == NULL) {
        // Handle malloc failure
        exit(EXIT_FAILURE);
    }
    strcpy(list[i], argv[i]);
}

// Null terminate the array
list[argc] = NULL;

execv(list[0], list);

// Free allocated memory
for (i = 0; i < argc; ++i) {
    free(list[i]);
}
free(list);
