#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char **vendas = malloc(sizeof(char*)); // Starting with space for 1 pointer.
    if (vendas == NULL) {
        perror("Initial malloc failed");
        return EXIT_FAILURE;
    }

    int size = 1;
    int current = 0;
    char buffer[50];
    char *token;
    FILE *fp = fopen("Vendas_1M.txt", "r");
    if (fp == NULL) {
        perror("Failed to open file");
        free(vendas);
        return EXIT_FAILURE;
    }

    while(fgets(buffer, 50, fp)) {
        token = strtok(buffer, "\n");
        if (size == current) {
            char **temp = realloc(vendas, sizeof(*vendas) * size * 2);
            if (temp == NULL) {
                perror("Realloc failed");
                // Free previously allocated memory
                for (int i = 0; i < current; ++i) {
                    free(vendas[i]);
                }
                free(vendas);
                fclose(fp);
                return EXIT_FAILURE;
            }
            vendas = temp;
            size *= 2;
        }
        vendas[current] = strdup(token);
        if (vendas[current] == NULL) {
            perror("strdup failed");
            // Free previously allocated memory
            for (int i = 0; i <= current; ++i) { // <= because current points to the current (failed) allocation
                free(vendas[i]);
            }
            free(vendas);
            fclose(fp);
            return EXIT_FAILURE;
        }
        printf("%d - %d - %s\n", current, size, vendas[current]);
        current++;
    }

    fclose(fp);

    // Remember to free the memory once you're done.
    for (int i = 0; i < current; ++i) {
        free(vendas[i]);
    }
    free(vendas);

    return 0;
}
