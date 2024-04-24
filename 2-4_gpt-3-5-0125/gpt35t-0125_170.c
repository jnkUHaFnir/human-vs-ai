bool unload(void)
{
    // Iterate over each bucket in the hash table
    for(int i = 0; i < N; i++)
    {
        // Get the first node in the bucket
        node *tmp = table[i];

        // Iterate over all the nodes in the bucket and free memory
        while(tmp != NULL)
        {
            node *del = tmp;
            tmp = tmp->next;
            free(del);
        }
        table[i] = NULL; // Update the table to reflect that the bucket is now empty
    }
    return true;
}
