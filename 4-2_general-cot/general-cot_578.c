static void free_envp(char **envp, int envp_size)
{
    if (envp == NULL) {
        return;
    }

    for (int i = 0; i < envp_size; i++) {
        if (envp[i] != NULL) {
            free(envp[i]);
        }
    }

    free(envp);
}
