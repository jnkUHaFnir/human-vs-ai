void Append(Data* head, char* name, char* lastname) {
    // Allocate memory for the new node
    Data* _newNode = (Data*)malloc(sizeof(Data));
    std::strcpy(_newNode->name, name);
    std::strcpy(_newNode->lastname, lastname);
    _newNode->next = NULL; // Initialize next pointer to NULL for the new node

    if ((*name != '\0') && (*lastname != '\0')) {
        // Special Case: If the list is empty
        if (head == NULL) {
            head = _newNode;
        } else {
            // Find the last node in the list
            Data* prt = head;
            while (prt->next != NULL) {
                prt = prt->next;
            }
            // Append the new node to the end of the list
            prt->next = _newNode;
        }
    }
}
