#include <stdio.h>

typedef struct {
    int *a;
    int *b;
    int *c;
    size_t cnt;
} str_t;

void save(const str_t * const str, const char *name) {
    FILE *f;
    int i;
    char buffer[30]; // Assuming maximum characters required for one line

    if (str->cnt == 0) return;

    f = fopen(name, "wb"); // Open file in binary write mode
    if (f == NULL) return;

    for (i = 0; i < str->cnt; i++) {
        sprintf(buffer, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        fwrite(buffer, sizeof(char), strlen(buffer), f); // Write the formatted string
    }
    
    fclose(f);
}

int main() {
    // Example usage
    str_t data = {0};
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[] = {7, 8, 9};
    data.a = a;
    data.b = b;
    data.c = c;
    data.cnt = 3;

    save(&data, "output.txt");

    return 0;
}
