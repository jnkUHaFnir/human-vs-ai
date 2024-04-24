#include <stdio.h>

typedef struct {
    int* a;
    int* b;
    int* c;
    size_t cnt;
} str_t;

void save(const str_t * const str, const char *name) {
    FILE* f;
    size_t i;
    char buffer[30]; // Assuming 10 digits per integer and 2 spaces between them

    if (str->cnt == 0)
        return;

    f = fopen(name, "w");
    if (f == NULL)
        return;

    for (i = 0; i < str->cnt; i++) {
        sprintf(buffer, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        fwrite(buffer, sizeof(char), strlen(buffer), f);
    }

    fclose(f);
}

int main() {
    // Sample usage
    str_t data = {
        .a = (int[]){1, 2, 3, 4},
        .b = (int[]){5, 6, 7, 8},
        .c = (int[]){9, 10, 11, 12},
        .cnt = 4
    };

    save(&data, "output.txt");

    return 0;
}
