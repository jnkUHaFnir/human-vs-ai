#include <stdio.h>
#include <string.h>

char* extractBaseName(const char* path) {
    const char* baseName = strrchr(path, '/');
    if(baseName == NULL) {
        return strdup(path); // Return the whole path if no '/'
    } else {
        return strdup(baseName + 1); // Return substring after the last '/'
    }
}

int main() {
    const char* path = "/opt/home/etc/sample";
    char* baseName = extractBaseName(path);

    printf("Base name: %s\n", baseName);

    free(baseName); // Don't forget to free the allocated memory
    return 0;
}
