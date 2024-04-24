#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mem;
void *ptr;

int main() {
    // Answer a)
    if (posix_memalign(&mem, 16, 1024) != 0) {
        printf("Memory alignment failed\n");
        return 1;
    }
    
    ptr = mem;

    memset_16aligned(ptr, 0, 1024);

    // Answer b)
    free(mem);
    
    return 0;
}
