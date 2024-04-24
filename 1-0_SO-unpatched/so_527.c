    int *a = malloc(sizeof(int) * 2);
    int *tmp = realloc(a, sizeof(int) * 4);
    if (tmp == NULL)
    {
        // Reallocation failed
    }
    else
    {
        a = tmp;
    }