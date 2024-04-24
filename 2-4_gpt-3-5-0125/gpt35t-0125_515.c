while (fscanf((*file), "%c", &c) != EOF)
{
    if (n < SIZE)
    {
        data[n++] = c;
    }
    else
    {
        SIZE *= 2;
        if ((data2 = (char*)realloc(data, SIZE * sizeof(char))) != NULL)
        {
            data = data2;
            data[n++] = c;
        }
        else
        {
            free(data);
            perror("realloc:");
        }
    }
}
