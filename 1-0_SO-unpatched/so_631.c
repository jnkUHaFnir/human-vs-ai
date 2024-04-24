   	int *data = malloc(10 * sizeof(int));
	int i;
    if(data == NULL)
    {
         perror("malloc");
         exit(EXIT_FAILURE);
    }
	for (i = 0; i < 10; i++)
	{
		data[i] = i;
	}
	data = realloc(data, 11 * sizeof(int));
    if(data == NULL)
    {
         perror("realloc");
         exit(EXIT_FAILURE);
    }
	data[10] = 10;
	for (i = 0; i < 11; i++)
		printf("%d ", data[i]);
	free(data);
	data = NULL;