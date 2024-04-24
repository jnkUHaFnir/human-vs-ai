#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char **vendas = NULL; // Change vendas to a pointer to pointer
    int size = 1;
    int current = 0;
    char buffer[50];
    char *token;
    FILE *fp = fopen("Vendas_1M.txt", "r");

    while(fgets(buffer, 50, fp)) {
        token = strtok(buffer, "\n");
        if (size == current) {
            vendas = realloc(vendas, sizeof(char*) * size * 2); // Correct reallocation
            size *= 2;
        }
        vendas[current] = strdup(token);
        printf("%d - %d - %s\n", current, size, vendas[current]);
        current++;
    }

    // Free memory
    for (int i = 0; i < current; i++) {
        free(vendas[i]);
    }
    free(vendas);
    fclose(fp);

    return 0;
}
