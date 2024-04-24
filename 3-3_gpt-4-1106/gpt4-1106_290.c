#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int size = 1;
    int current = 0;
    char buffer[50];
    char *token;
    FILE *fp = fopen("Vendas_1M.txt", "r");
    if (!fp) { perror("File opening failed"); return EXIT_FAILURE; }
    
    // Allocating an initial array of char* with size 1.
    char **vendas = malloc(sizeof(char*) * size);

    while(fgets(buffer, 50, fp)) {
        token = strtok(buffer, "\n");
        // Ensure size is enough to accommodate the next item.
        if (size == current) {
            // Increase size by reallocating the vendas array.
            char **temp = realloc(vendas, sizeof(char*) * size * 2);
            if (temp == NULL) {
                // Handle allocation failure
                perror("realloc failed");
                for (int i = 0; i < current; ++i) {
                    free(vendas[i]);
                }
                free(vendas);
                fclose(fp);
                return EXIT_FAILURE;
            }
            vendas = temp; // Update vendas with the new pointer.
            size *= 2;
        }
        vendas[current] = strdup(token);
        printf("%d - %d - %s\n", current, size, vendas[current]);
        current++;
    }
    fclose(fp);
    // Cleaning up: Don't forget to free the strdup'ed strings
    // and the vendas array itself.
    for (int i = 0; i < current; i++) {
        free(vendas[i]);
    }
    free(vendas);

    return 0;
}
