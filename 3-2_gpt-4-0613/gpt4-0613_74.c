// create the first node 
q = (struct node *)malloc(sizeof(struct node));
q->data = item;
q->next = NULL; 
...
p->next = q;
p = p->next;
struct node {
    char *data;
    struct node *next;
};
.....
struct node *p, *head = NULL;
// then in your while loop
q = malloc(sizeof(struct node));
q->data = strdup(token);
q->next = NULL;
if(head == NULL) {
    head = p = q;
} else {
    p->next = q;
    p = p->next;
}
