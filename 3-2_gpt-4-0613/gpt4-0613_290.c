char **vendas = malloc(size * sizeof(char *));
vendas = realloc(vendas, sizeof(char *) * size * 2);
int main(int argc, char *argv[]) {
    int size = 1;
    int current = 0;
    char buffer[50];
    char *token;
    FILE *fp = fopen("Vendas_1M.txt", "r");
    char **vendas = malloc(size * sizeof(char *));

    if (vendas == NULL) {
        printf("Failed to allocate memory.\n"); // or handle error in any other way you see fit
        return 1;
    }

    while(fgets(buffer, 50, fp)) {
        token = strtok(buffer, "\n");
        if (size == current) {
            vendas = realloc(vendas, sizeof(char *) * size * 2);
            if (vendas == NULL) {
                printf("Failed to reallocate memory.\n"); // or handle error in any other way you see fit
                return 1;
            }
            size *= 2;
        }
        vendas[current] = strdup(token);
        printf("%d - %d - %s\n", current, size, vendas[current]);
        current++;
    }

    // don't forget to free the memory at the end
    for (int i = 0; i < current; i++) {
        free(vendas[i]);
    }
    free(vendas);

    return 0;
}
