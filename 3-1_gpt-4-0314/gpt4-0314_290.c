char **vendas;
int size = 1;
vendas = malloc(sizeof(char*) * size);
vendas = realloc(vendas, sizeof(char*) * size * 2);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char **vendas;
    int size = 1;
    int current = 0;
    char buffer[50];
    char *token;
    FILE *fp = fopen("Vendas_1M.txt", "r");
    
    vendas = malloc(sizeof(char*) * size);

    while(fgets(buffer, 50, fp)) {
        token = strtok(buffer, "\n");
        if (size == current) {
            vendas = realloc(vendas, sizeof(char*) * size * 2);
            size *= 2;
        }
        vendas[current] = strdup(token);
        printf("%d - %d - %s\n", current, size, vendas[current]);
        current++;
    }
}
