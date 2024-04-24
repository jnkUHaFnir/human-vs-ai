else if(table[code] != NULL)
{
    node *pointer = table[code];
    while(pointer->next != NULL)
    {
        tmp->next = table[code];
        table[code] = tmp;
    }
}
else
{
    tmp->next = table[code];
    table[code] = tmp;
}
while(tmp->next != NULL)
{
    // Your comparison logic
    if(tmp->next != NULL)
    {
        tmp = tmp->next;   
    }
}
while(tmp != NULL)
{
    if(strcmp(tmp->word, w) == 0)
    {
        return true;
    }
    tmp = tmp->next;   
}
bool unload(void)
{
    node *tmp = NULL;
    node *del = NULL;
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
unsigned int size(void)
{
    return count;
}
