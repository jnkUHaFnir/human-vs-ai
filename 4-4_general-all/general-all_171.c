// Unloads dictionary from memory, returning true if successful else false
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
        table[i] = NULL; // Resetting the head of the linked list after freeing all nodes
    }
    return true;
}
