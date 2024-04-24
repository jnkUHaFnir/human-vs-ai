#include <stdlib.h>

static void free_envp(char **envp, int env_count) {
    if (envp == NULL) {
        // Handle the case where envp is NULL
        return;
    }

    // Free each individual string in the array
    for (int i = 0; i < env_count; i++) {
        free(envp[i]);
    }

    // Free the array itself
    free(envp);
}
