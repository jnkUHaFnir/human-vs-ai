#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* repeat_str(const char* str, size_t count){
    if (count == 0) return NULL;

    char* ret = malloc(strlen(str) * count + 1);
    if (ret == NULL) return NULL;

    strcpy(ret, str);
    for (size_t i = 1; i < count; ++i)
        strcat(ret, str);

    return ret;
}

int main() {
    char* str = repeat_str("-", 10);  // Replace 10 with the number of repeats you want

    printf("%s\n", str);

    free(str);
    return 0;
}
