static void free_envp(char **envp, int size)
{
    if (envp == NULL) {
        return;
    }

    for (int i = 0; i < size; i++) {
        if (envp[i] != NULL) {
            free(envp[i]);
        }
    }

    free(envp);
}
