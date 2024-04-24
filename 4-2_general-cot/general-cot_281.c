#include <stdio.h>

int main() {
    #if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
        printf("Variable Length Arrays (VLAs) are supported.\n");
    #else
        printf("Variable Length Arrays (VLAs) are not supported.\n");
    #endif

    return 0;
}
