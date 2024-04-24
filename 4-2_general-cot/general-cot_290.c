#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char **vendas = NULL; // Use double pointer to store pointer to strings
    int size = 1;
    int current = 0;
    char buffer[50];
    char *token;
    FILE *fp = fopen("Vendas_1M.txt", "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while(fgets(buffer, 50, fp)) {
        token = strtok(buffer, "\n");
        if (current == size) {
            size *= 2;
            vendas = realloc(vendas, sizeof(char*) * size); // Correct reallocation for the array of strings
            if (vendas == NULL) {
                perror("Error reallocating memory");
                return 1;
            }
        }
        vendas[current] = strdup(token);
        printf("%d - %d - %s\n", current, size, vendas[current]);
        current++;
    }

    for (int i = 0; i < current; i++) {
        free(vendas[i]); // Free memory allocated for each string
    }
    free(vendas); // Free memory allocated for array

    fclose(fp);

    return 0;
}
