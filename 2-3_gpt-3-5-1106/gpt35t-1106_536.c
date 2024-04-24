void pop (linkedPtr* hd)
{
    linkedPtr tmp = *hd;
    *hd = (*hd)->next;
    free(tmp);
}
pop (&head);
