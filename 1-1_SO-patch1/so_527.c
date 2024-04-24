    int *a = malloc(sizeof(int) * 2);
    a = realloc(a, 4);  // You should use different variable if realloc failed