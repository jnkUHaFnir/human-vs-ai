void addRecord(const char *pName, int ms1)
{   
    struct node* newNode = (struct node*) malloc(sizeof(struct node)); // allocate node

    int nameLength = strlen(pName); // use strlen instead of tStrlen
    newNode->name = (char *) malloc(nameLength + 1); // allocate memory for the name + 1 for null terminator
    strcpy(newNode->name, pName); // use strcpy instead of tStrcpy

    newNode->m1 = ms1;
    newNode->next = head; // link the old list off the new node
    head = newNode;
}
