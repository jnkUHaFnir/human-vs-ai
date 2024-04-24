// Unloads dictionary from memory, returning true if successful else false
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
        table[i] = NULL; // Set the head of the linked list to NULL after freeing all nodes
    }

    return true;
}
