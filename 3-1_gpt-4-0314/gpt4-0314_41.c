#include <string.h>
#include <stdbool.h>

bool has_extension(const char *fpath, const char *ext) {
    // Find the last occurrence of the period character.
    const char *dot = strrchr(fpath, '.');

    // If a period was found and the extensions match, return true.
    return dot && strcmp(dot + 1, ext) == 0;
}

int main() {
    const char *fpath = "foo.out";

    int binFile = 0;
    if (has_extension(fpath, "exe") || has_extension(fpath, "o")) {
        binFile = 1;
    }

    printf("binFile: %d\n", binFile);
    return 0;
}
