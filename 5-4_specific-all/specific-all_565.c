#include <stdio.h>
#include <string.h>

char* extract_base_name(const char *path) {
    if (path == NULL || *path == '\0') {
        return NULL;
    }

    const char *baseName = strrchr(path, '/');

    if (baseName != NULL) {
        // Move past the last '/' character
        baseName++;
        return strdup(baseName); // Don't forget to free the memory after use
    }

    // No path separator found, return the original string
    return strdup(path); // Don't forget to free the memory after use
}

int main() {
    const char *path = "/opt/home/etc/sample";
    char *baseName = extract_base_name(path);

    if (baseName != NULL) {
        printf("Base name: %s\n", baseName);
        free(baseName);
    }

    return 0;
}
