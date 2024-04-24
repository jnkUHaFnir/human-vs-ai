#include <stdio.h>
#include <string.h>

int isExecutableOrObjectFile(const char *fpath) {
    const char *extension = strrchr(fpath, '.'); // Find the last occurrence of '.'

    if (extension != NULL) {
        // Compare the file extension with ".exe" or ".o" including the NULL terminator
        if ((strcmp(extension, ".exe") == 0) || (strcmp(extension, ".o") == 0)) {
            return 1;  // File is ".exe" or ".o"
        }
    }

    return 0;  // Not an executable or object file
}

int main() {
    const char *file1 = "foo.exe";
    const char *file2 = "bar.o";
    const char *file3 = "foo.out";
    const char *file4 = "foo.execute";

    printf("%d\n", isExecutableOrObjectFile(file1));  // Should return 1
    printf("%d\n", isExecutableOrObjectFile(file2));  // Should return 1
    printf("%d\n", isExecutableOrObjectFile(file3));  // Should return 0
    printf("%d\n", isExecutableOrObjectFile(file4));  // Should return 0

    return 0;
}
