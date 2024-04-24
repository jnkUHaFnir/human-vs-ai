void Append(Data* head, char* name, char* lastname) {
    if (head == NULL) {
        // Handle case where the list is empty
        return;
    }

    Data* _newNode = (Data*)malloc(sizeof(Data));
    if (_newNode == NULL) {
        // Handle memory allocation failure
        return;
    }
    
    std::strcpy(_newNode->name, name);
    std::strcpy(_newNode->lastname, lastname);
    _newNode->next = NULL; // Initialize next pointer of new node

    if ((*name != '\0') && (*lastname != '\0')) {
        // find the last node in the list:
        Data* prt = head;
        if (*prt->name == '\0') {
            // Special case: head node is empty
            std::strcpy(prt->name, name);
            std::strcpy(prt->lastname, lastname);
        } else {
            while (prt->next != NULL) {
                prt = prt->next;
            }
            prt->next = _newNode; // Append the new node to the end of the list
        }
    }
}
