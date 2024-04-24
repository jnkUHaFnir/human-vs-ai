#include <string.h>

int checkFileExtension(const char *fpath) {
    if (strncmp(fpath + strlen(fpath) - 4, ".exe", 4) == 0 ||
        strncmp(fpath + strlen(fpath) - 2, ".o", 2) == 0) {
        return 1; // File is .exe or .o
    }
    return 0; // File is not .exe or .o
}

int main() {
    const char *fpath1 = "foo.exe";
    const char *fpath2 = "foo.o";
    const char *fpath3 = "foo.out";
    const char *fpath4 = "foo.execute";

    printf("%s: %d\n", fpath1, checkFileExtension(fpath1));
    printf("%s: %d\n", fpath2, checkFileExtension(fpath2));
    printf("%s: %d\n", fpath3, checkFileExtension(fpath3));
    printf("%s: %d\n", fpath4, checkFileExtension(fpath4));

    return 0;
}
