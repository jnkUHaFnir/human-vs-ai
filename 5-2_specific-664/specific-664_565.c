#include <stdio.h>
#include <string.h>

const char* extract_base_name(const char* path) {
    const char* base_name = strrchr(path, '/'); // Find last occurrence of '/'
  
    if (base_name != NULL) {
        // Move to the character after the last '/'
        base_name++;
    } else {
        // No '/' found, return the original path
        base_name = path;
    }

    return base_name;
}

int main() {
    const char* path = "/opt/home/etc/sample";
    const char* base_name = extract_base_name(path);

    printf("Base name: %s\n", base_name);

    return 0;
}
