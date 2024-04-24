title = (char*)malloc(100*sizeof(char)); // Allocate memory for a string of length 100

if (title == NULL)
{
    printf ("Error: memory allocation failed\n");
    return 1;
}

fscanf(fp, "<%s>", title);
free(title);
