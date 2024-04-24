if(table[code] != NULL)
{
    node *pointer = table[code];
    while(pointer->next != NULL)
    {
        tmp->next = table[code];
        table[code] = tmp;
    }
    //YOU ARE HERE
}
if(table[code] != NULL)
{
    node *pointer = table[code];
    while(pointer->next != NULL)
    {
        pointer = pointer->next;
    }
    tmp->next = pointer->next;
    pointer->next = tmp;
}
