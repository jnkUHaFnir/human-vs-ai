// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int ch = hash(word);
    char w[LENGTH + 1];
  
    for(int i = 0; i < LENGTH; i++)
    {
        w[i] = tolower(word[i]);
    }
    w[LENGTH] = '\0';

    node *tmp = table[ch];
    while (tmp != NULL)
    {
        if (strcmp(tmp->word, w) == 0)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file.\n");
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
            while (pointer->next != NULL)
            {
                pointer = pointer->next;
            }
            pointer->next = tmp;
        }
    }

    fclose(file);
    return true;
}
