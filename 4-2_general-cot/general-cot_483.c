#include <stdio.h>

typedef struct {
    int *a;
    int *b;
    int *c;
    int cnt;
} str_t;

void save(const str_t * const str, const char *name) {
    FILE* f;
    int i;
    int buffer[3];

    if(str->cnt == 0)
        return;

    f = fopen(name, "wb"); // Open file in binary mode
    if(f == NULL)
        return;

    for(i = 0; i < str->cnt; i++) {
        buffer[0] = str->a[i];
        buffer[1] = str->b[i];
        buffer[2] = str->c[i];
        fwrite(buffer, sizeof(int), 3, f); // Write all three integers in one go
    }

    fclose(f);
}

int main() {
    // Example usage
    str_t data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, 3};
    save(&data, "output.txt");

    return 0;
}
