while (x == 1) {
    current->next = (list*)malloc(sizeof(list));
    printf("enter data:");
    scanf("%d", &current->next->data);
    current->next->prev = current; // Set the prev pointer to the current node
    current->next->next = NULL;
    current = current->next;
    end = current;
    printf("do you want to enter more:");
    scanf("%d", &x);
}
newn = head;
while (newn != NULL) {
    printf("%d:%d:%d->", newn->prev, newn->data, newn->next);
    newn = newn->next;
}
while (end != NULL) { // Change the condition to while end is not NULL
    printf("%d", end->data);
    end = end->prev;
}
