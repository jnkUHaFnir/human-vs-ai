#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char **vendas = malloc(sizeof(char*));
    int size = 1;
    int current = 0;
    char buffer[50];
    char *token;
    FILE *fp = fopen("Vendas_1M.txt", "r");

    while (fgets(buffer, 50, fp)) {
        token = strtok(buffer, "\n");
        if (size == current) {
            size *= 2;
            vendas = realloc(vendas, sizeof(char*) * size);
            if (vendas == NULL) {
                printf("Memory reallocation failed.\n");
                exit(EXIT_FAILURE);
            }
        }
        vendas[current] = strdup(token);
        printf("%d - %d - %s\n", current, size, vendas[current]);
        if (vendas[current] == NULL) {
            printf("Memory allocation failed for vendas[%d].\n", current);
            exit(EXIT_FAILURE);
        }
        current++;
    }

    // Free memory for vendas array
    for (int i = 0; i < current; i++) {
        free(vendas[i]);
    }
    free(vendas);

    fclose(fp);
    return 0;
}
