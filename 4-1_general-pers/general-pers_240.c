#include <stdio.h>

typedef struct {
    int *a;
    int *b;
    int *c;
    int cnt;
} str_t;

void save(const str_t * const str, const char *name) {
    FILE *f;
    int i;

    if(str->cnt == 0) {
        return;
    }

    f = fopen(name, "wb"); // Open file in binary write mode for faster I/O

    if(f == NULL) {
        return;
    }

    // Temporary buffer to hold formatted integers
    char buffer[20]; // Assuming a maximum of 10 digits per integer

    for(i = 0; i < str->cnt; i++) {
        int len = sprintf(buffer, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        fwrite(buffer, 1, len, f); // Write formatted string to file
    }

    fclose(f);
}

int main() {
    str_t data = {.a = (int[]){1, 2, 3, 4}, .b = (int[]){5, 6, 7, 8}, .c = (int[]){9, 10, 11, 12}, .cnt = 4};
    save(&data, "output.txt");

    return 0;
}
