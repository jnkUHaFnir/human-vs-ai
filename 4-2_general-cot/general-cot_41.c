#include <stdio.h>
#include <string.h>

int isExecutableOrObjectFile(const char* fpath) {
    size_t len = strlen(fpath);
    
    if (len >= 4 && strcmp(fpath + len - 4, ".exe") == 0) {
        return 1; // File ends with '.exe\0'
    }
    
    if (len >= 2 && strcmp(fpath + len - 2, ".o") == 0) {
        return 1; // File ends with '.o\0'
    }
    
    return 0; // Not an .exe or .o file
}

int main() {
    const char* file1 = "example.exe";
    const char* file2 = "test.o";
    const char* file3 = "foo.out";
    const char* file4 = "foo.execute";
    
    printf("%s is executable or object file: %d\n", file1, isExecutableOrObjectFile(file1));
    printf("%s is executable or object file: %d\n", file2, isExecutableOrObjectFile(file2));
    printf("%s is executable or object file: %d\n", file3, isExecutableOrObjectFile(file3));
    printf("%s is executable or object file: %d\n", file4, isExecutableOrObjectFile(file4));
    
    return 0;
}
