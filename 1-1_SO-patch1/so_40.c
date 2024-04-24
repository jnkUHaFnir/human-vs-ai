    Query new = malloc(sizeof(struct Query));
    if (new == NULL)
        printf ("Error\n");
    new->pages = malloc(4*sizeof(int));
    if (new->pages == NULL)
       printf ("Error\n");