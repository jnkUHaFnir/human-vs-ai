bool check(const char *word)
{
    node *tmp = NULL;
    int ch = hash(word);
    int len = strlen(word);
    char w[len + 1];

    for (int i = 0; i < len; i++)
    {
        w[i] = tolower(word[i]);
    }
    w[len] = '\0';

    tmp = table[ch];
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
