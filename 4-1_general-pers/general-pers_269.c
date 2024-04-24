char **list = malloc((argc + 1) * sizeof(char*)); // +1 for the NULL terminator at the end
if (list == NULL) {
    // Handle malloc failure
}

int i;
for (i = 0; i < argc; ++i) {
    list[i] = malloc(strlen(argv[i]) + 1);
    if (list[i] == NULL) {
        // Handle malloc failure
        break; // Exit the loop if malloc fails
    }
    strcpy(list[i], argv[i]);
}
list[argc] = NULL; // Add NULL terminator at the end of the array

execv(list[0], list);
