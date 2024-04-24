static void free_envp(char **envp, size_t size)
{
    if (envp == NULL) {
        return;
    }

    for (size_t i = 0; i < size; i++) {
        free(envp[i]);
    }

    free(envp);
}
