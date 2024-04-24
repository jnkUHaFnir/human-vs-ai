static void free_envp(char **envp)
{
    if (envp == NULL) {
        return; // nothing to free
    }

    // free each string in the envp array
    for (int i = 0; envp[i] != NULL; i++) {
        free(envp[i]);
    }

    // free the envp array itself
    free(envp);
}
