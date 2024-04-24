char *vendas[1];
*vendas = realloc(*vendas, sizeof(vendas[0]) * size * 2);
*vendas = realloc(*vendas, sizeof(*vendas) * size * 2);
