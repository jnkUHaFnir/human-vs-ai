#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool has_extension(const char *fpath, const char *extension) {
    if (!fpath || !extension) return false;

    size_t fpath_len = strlen(fpath);
    size_t extension_len = strlen(extension);

    // Check if the extension is shorter than the file path
    if (extension_len >= fpath_len) return false;

    // Point to the position where the extension would start if present
    const char *fpath_extension = fpath + fpath_len - extension_len;

    // Compare the end of the file path with the extension
    return strcmp(fpath_extension, extension) == 0;
}

int main() {
    const char *files[] = {"test.exe", "example.o", "foo.execute", "bar.out", "program.exe ", "binary.o"};
    int i;
    for (i = 0; i < sizeof(files) / sizeof(files[0]); ++i) {
        int binFile = 0;
        if (has_extension(files[i], ".exe") || has_extension(files[i], ".o")) {
            binFile = 1;
        }
        printf("File '%s' is%s a binary file.\n", files[i], binFile ? "" : " not");
    }
    return 0;
}
