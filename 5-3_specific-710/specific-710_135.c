void addRecord(const char *pName, int ms1)
{   
    struct node* newNode = (struct node*) malloc(sizeof(struct node)); // allocate node

    int nameLength = strlen(pName);
    newNode->name = (char *) malloc(nameLength + 1); // allocate memory for name and null terminator
    strcpy(newNode->name, pName);

    newNode->m1 = ms1;
    newNode->next = head; // link the old list off the new node
    head = newNode;
}
if(current->name != 0)
{
    free(current->name);
}
