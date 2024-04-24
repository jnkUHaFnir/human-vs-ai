#include <stdio.h>
#include <string.h>

const char* extract_base_name(const char* path) {
    if (path == NULL) {
        return NULL;
    }

    const char* base_name = strrchr(path, '/');
    if (base_name == NULL) {
        // If no '/' character found, return the original path
        return path;
    }

    return base_name + 1; // +1 to move past the '/'
}

int main() {
    const char* path = "/opt/home/etc/sample";
    const char* base_name = extract_base_name(path);

    printf("Base name: %s\n", base_name);

    return 0;
}
