bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node *tmp = table[i];
        while (tmp != NULL)
        {
            node *del = tmp;
            tmp = tmp->next;
            free(del);
        }
        table[i] = NULL; // Reset the table bucket after freeing all nodes in the linked list
    }
    return true;
}
