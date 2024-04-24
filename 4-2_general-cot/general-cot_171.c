bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("could not open file.\n");
        return false;
    }
    
    char temp[LENGTH + 1];
    while (fscanf(file, "%s", temp) != EOF)
    {
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL)
        {
            fclose(file);
            return false;
        }
        
        strcpy(tmp->word, temp);
        unsigned int code = hash(temp);
        
        tmp->next = table[code]; // Insert at the beginning of the linked list
        table[code] = tmp;
        count++;
    }
    
    fclose(file);
    return true;
}
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        while (tmp != NULL)
        {
            node *del = tmp;
            tmp = tmp->next;
            free(del);
        }
        table[i] = NULL; // Reset the table entry to NULL after freeing all nodes
    }

    return true;
}
