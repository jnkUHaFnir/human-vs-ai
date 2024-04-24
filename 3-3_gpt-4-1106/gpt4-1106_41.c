#include <stdbool.h>
#include <string.h>

bool hasFileExtension(const char *fpath, const char *ext) {
    if (fpath == NULL || ext == NULL) {
        return false;
    }

    size_t fpath_len = strlen(fpath);
    size_t ext_len = strlen(ext);

    // The file path must be longer than the extension for a match to occur
    if (fpath_len <= ext_len) {
        return false;
    }

    // Compare the end of the string with the extension
    return strcmp(fpath + fpath_len - ext_len, ext) == 0;
}

int main() {
    const char *fpath = "yourfile.exe"; // Replace with the actual file path
    int binFile = 0;

    if (hasFileExtension(fpath, ".exe") || hasFileExtension(fpath, ".o")) {
        binFile = 1;
    }

    // Rest of your code...

    return 0;
}
