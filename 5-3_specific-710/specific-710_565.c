#include <stdio.h>
#include <string.h>

char* extractBaseName(const char* path) {
    const char* baseName = strrchr(path, '/');
    if (baseName == NULL) {
        return NULL;
    } else {
        return strdup(baseName + 1);
    }
}

int main() {
    const char* path = "/opt/home/etc/sample";
    char* baseName = extractBaseName(path);

    if (baseName != NULL) {
        printf("Base name: %s\n", baseName);
        free(baseName);
    } else {
        printf("Base name not found\n");
    }

    return 0;
}
