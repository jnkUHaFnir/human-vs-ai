struct node {
    char *name;
    int m1;
    struct node *next;
};

struct node* head = NULL; //start with NULL list

void addRecord(const char *pName, int ms1)
{   
    struct node* newNode = (struct node*) malloc(sizeof(struct node)); // allocate node

    if(newNode == NULL) {
        // Handle allocation failure
        return;
    }

    int nameLength = strlen(pName); // Corrected from tStrlen to strlen
    newNode->name = (char *) malloc(nameLength + 1); // Allocate space for the string and null terminator

    if(newNode->name == NULL) {
        free(newNode); // Clean up allocated node
        return;
    }

    strcpy(newNode->name, pName);

    newNode->m1 = ms1;
    newNode->next = head; // link the old list off the new node
    head = newNode;
}

void clear(void)
{
    struct node* current = head;
    struct node* next;
    while (current != NULL) 
    {
        next = current->next; // note the next pointer

        if(current->name != NULL)
        {
            free(current->name);
            current->name = NULL; // Set to NULL after freeing to avoid dangling pointers
        }
        
        free(current); // delete the node
        current = next; // advance to the next node
    }
    head = NULL;
}
