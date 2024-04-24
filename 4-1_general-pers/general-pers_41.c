#include <stdio.h>
#include <string.h>

int isExecutableFile(const char *fpath) {
    const char *exe = ".exe";
    const char *obj = ".o";
    int len = strlen(fpath);

    if (len >= 5 && strcmp(fpath + len - 4, exe) == 0) {
        return 1;
    }

    if (len >= 3 && strcmp(fpath + len - 2, obj) == 0) {
        return 1;
    }

    return 0;
}

int main() {
    const char *filename1 = "file.exe";
    const char *filename2 = "file.o";
    const char *filename3 = "foo.out";
    const char *filename4 = "foo.execute";

    if (isExecutableFile(filename1)) {
        printf("%s is an executable file.\n", filename1);
    } else {
        printf("%s is not an executable file.\n", filename1);
    }

    if (isExecutableFile(filename2)) {
        printf("%s is an executable file.\n", filename2);
    } else {
        printf("%s is not an executable file.\n", filename2);
    }

    if (isExecutableFile(filename3)) {
        printf("%s is an executable file.\n", filename3);
    } else {
        printf("%s is not an executable file.\n", filename3);
    }

    if (isExecutableFile(filename4)) {
        printf("%s is an executable file.\n", filename4);
    } else {
        printf("%s is not an executable file.\n", filename4);
    }

    return 0;
}
