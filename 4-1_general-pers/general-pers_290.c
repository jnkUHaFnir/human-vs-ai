#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char **vendas = NULL;  // Pointer to array of char pointers
    int size = 1;
    int current = 0;
    char buffer[50];
    char *token;
    FILE *fp = fopen("Vendas_1M.txt", "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    vendas = (char **)malloc(sizeof(char *) * size);  // Allocate memory for array of char pointers

    if (vendas == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    while (fgets(buffer, 50, fp)) {
        token = strtok(buffer, "\n");
        
        if (token == NULL) {
            continue;  // Skip empty lines
        }

        if (size == current) {
            char **temp = (char **)realloc(vendas, sizeof(char *) * size * 2);
            if (temp == NULL) {
                perror("Memory reallocation failed");
                // Clean up existing memory
                for (int i = 0; i < current; i++) {
                    free(vendas[i]);
                }
                free(vendas);
                return 1;
            }
            vendas = temp;
            size *= 2;
        }

        vendas[current] = strdup(token);  // Allocate memory for the current string
        
        if (vendas[current] == NULL) {
            perror("Memory allocation failed");
            // Clean up existing memory
            for (int i = 0; i < current; i++) {
                free(vendas[i]);
            }
            free(vendas);
            return 1;
        }

        printf("%d - %d - %s\n", current, size, vendas[current]);
        current++;
    }

    // Clean up memory
    for (int i = 0; i < current; i++) {
        free(vendas[i]);
    }
    free(vendas);
    fclose(fp);

    return 0;
}
