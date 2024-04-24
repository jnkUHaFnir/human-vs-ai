void free_envp(char **envp)
{
    char** temp = envp;
    while(*temp) {
        free(*temp);
        temp++;
    }
    free(envp);
}
