bool check(const char *word)
{
    node *tmp = NULL;
    int ch = hash(word);
    int len = strlen(word);
    char w[len+1];
  
    for (int i = 0; i < len; i++)
    {
        w[i] = tolower(word[i]);
    }
    w[len] = '\0';
    
    tmp = table[ch];
    while(tmp != NULL)
    {
        if(strcmp(tmp->word, w) == 0)
        {
            return true;
        }
        tmp = tmp->next;
    }
    
    return false;
}
bool load(const char *dictionary)
{
    // existing code

    while(fscanf(file, "%s", temp) != EOF)
    {
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL)
        {
            fclose(file);
            return false;
        }
        strcpy(tmp->word, temp);
        tmp->next = NULL;
        unsigned int code = hash(temp);
        count++;

        if (table[code] == NULL)
        {
            table[code] = tmp;
        }
        else
        {
            node *pointer = table[code];
            while(pointer->next != NULL)
            {
                pointer = pointer->next;
            }
            pointer->next = tmp;
        }
    }

    fclose(file);
    return true;
}
