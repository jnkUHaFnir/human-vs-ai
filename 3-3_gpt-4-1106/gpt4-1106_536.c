void pop (linkedPtr hd)
{
    linkedPtr tmp = hd;
    hd = hd->next;
    free (tmp);
}
void pop (linkedPtr* hd)
{
    if (*hd != NULL)
    {
        linkedPtr tmp = *hd;
        *hd = (*hd)->next;
        free (tmp);
    }
}
pop(&head);
