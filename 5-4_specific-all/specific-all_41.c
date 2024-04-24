#include <string.h>

// Function to check if the file extension matches '.exe' or '.o'
int isExecutableFile(const char* fpath) {
    size_t len = strlen(fpath);
    if (len >= 4) {
        if (strcmp(fpath + len - 4, ".exe") == 0 || strcmp(fpath + len - 2, ".o") == 0) {
            return 1; // File extension matches '.exe' or '.o'
        }
    }
    return 0; // File extension does not match
}

int main() {
    const char* fpath = "foo.o";
    int binFile = isExecutableFile(fpath);

    if (binFile) {
        // File is an executable file
        // Proceed with your logic here
    }

    return 0;
}
