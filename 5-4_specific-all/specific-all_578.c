static void free_envp(char **envp)
{
    if (envp == NULL) {
        // Optionally handle this case, depending on your program's logic
        return;
    }

    free(*envp); // Assuming you are freeing the first element pointed to by envp
    *envp = NULL; // Set the pointer to NULL to avoid double-free issues
}
