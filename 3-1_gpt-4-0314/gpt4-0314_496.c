current->next->prev = current->next;
current->next->prev = current;
while(x == 1) {
    current->next = (list*)malloc(sizeof(list));
    printf("enter data:");
    scanf("%d", &current->next->data);
    current->next->prev = current; // <- fix here
    current->next->next = NULL;
    current = current->next;
    end = current;
    printf("do yo want to enter more:");
    scanf("%d", &x);
}
