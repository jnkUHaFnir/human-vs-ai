void addRecord(const char *pName, int ms1)
{   
    struct node* newNode = (struct node*) malloc(sizeof(struct node)); // allocate node

    int nameLength = strlen(pName);
    newNode->name = (char *) malloc(nameLength + 1); // allocate memory with space for null terminator
    if(newNode->name != NULL) // Check if allocation was successful
    {
        strcpy(newNode->name, pName);
    }
    else
    {
        // Handle memory allocation failure
        free(newNode);
        return;
    }

    newNode->m1 = ms1;
    newNode->next = head; // link the old list off the new node
    head = newNode;
}
