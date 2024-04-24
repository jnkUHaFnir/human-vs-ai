#include <stdio.h>

typedef struct {
    int *a;
    int *b;
    int *c;
    int cnt;
} str_t;

void save(const str_t * const str, const char *name)
{
    FILE* f;
    int i;
    char buffer[16]; // Assumption: Maximum 10 digits per integer plus space and newline

    if(str->cnt == 0)
        return;
    
    f = fopen(name, "w");
    if(f == NULL)
        return;
    
    for(i = 0; i < str->cnt; i++)
    {
        sprintf(buffer, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        fwrite(buffer, sizeof(char), strlen(buffer), f);
    }
    
    fclose(f);
}

int main() {
    // Example usage
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[] = {7, 8, 9};
    
    str_t example = {a, b, c, 3};
    
    save(&example, "output.txt");
    
    return 0;
}
