#include <string.h>

// ...

char *extension = strrchr(fpath, '.');
if(extension != NULL) {
    if(strcmp(extension, ".exe") == 0 || strcmp(extension, ".o") == 0) {
        binFile = 1;
    }
}
