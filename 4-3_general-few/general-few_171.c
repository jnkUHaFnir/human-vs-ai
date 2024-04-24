bool check(const char *word)
{
    unsigned int ch = hash(word);
    char w[LENGTH + 1];
    
    for (int i = 0; i < strlen(word); i++)
    {
        w[i] = tolower(word[i]);
    }
    w[strlen(word)] = '\0';
    
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
bool unload(void)
{
    node *tmp = NULL;
    node *del;
    for(int i = 0; i < N; i++)
    {
        tmp = table[i];
        while(tmp != NULL)
        {
            del = tmp;
            tmp = tmp->next;
            free(del);
        }
    }
    return true;
}
``` 

These changes should help mitigate the segmentation fault issue in your program.
