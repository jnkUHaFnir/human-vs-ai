typedef struct Data {
    char name[100];    // Ensure these sizes can accommodate the strings being copied.
    char lastname[100];
    struct Data* next;
} Data;

void Append(Data* head, char* name, char* lastname) {
    if (!head || !name || !lastname) return;
    
    Data* _newNode = malloc(sizeof(Data));
    if (!_newNode) return; // Could not allocate memory

    // Ensure the new node points to NULL to indicate end of list
    _newNode->next = NULL;
    strcpy(_newNode->name, name);
    strcpy(_newNode->lastname, lastname);

    // Iterator
    Data* ptr = head;
    if ((*name != '\0') && (*lastname != '\0')) {
        if (head->name[0] == '\0') {
            strcpy(head->name, name);
            strcpy(head->lastname, lastname);
            free(_newNode); // Since we are not using the new node
        } else {
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = _newNode;
        }
    } else {
        free(_newNode); // Name or lastname empty - don't append
    }
}
