static void free_envp(char **envp) {
    if (envp == NULL) return; // Guard against NULL pointer

    char **temp = envp;
    while (*temp != NULL) {
        free(*temp); // Free each string
        temp++;
    }
    free(envp); // Free the array of pointers
}
