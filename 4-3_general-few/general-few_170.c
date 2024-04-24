bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        while(tmp != NULL)
        {
            node *del = tmp;
            tmp = tmp->next;
            free(del);
        }
    }
    
    return true;
}
