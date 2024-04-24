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
