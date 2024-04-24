    #include <stdio.h>
    #include <stdlib.h>
    
    int main(int argc, char *argv[]) {
        char buffer[50];
        char **vendas = NULL;
        size_t size = 0;
        size_t current = 0;
        char *token;
        FILE *fp;
    
        fp = fopen("Vendas_1M.txt", "r");
        if (fp == NULL) {
            printf("cannot open file Vendas_1M.txt\n");
            return 1;
        }
        while (fgets(buffer, sizeof buffer, fp)) {
            token = strtok(buffer, "\n");
            if (size >= current) {
                size = (size == 0) ? 4 : size * 2;
                vendas = realloc(vendas, sizeof(*vendas) * size;
                if (vendas == NULL) {
                    printf("allocation failure\n");
                    return 1;
                }
            }
            vendas[current] = strdup(token);
            printf("%d - %d - %s\n", current, size, vendas[current]);
            current++;
        }
        /* ... */
        return 0;
    }    