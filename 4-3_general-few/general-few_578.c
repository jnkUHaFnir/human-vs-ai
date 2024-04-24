static void free_envp(char **envp, int size)
{
    for (int i = 0; i < size; i++) {
        free(envp[i]);
    }
    free(envp);
}
