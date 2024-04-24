void Append(Data* head, char* name, char* lastname) { 
    Data* _newNode = (Data*)malloc(sizeof(Data));
    std::strcpy(_newNode->name, name);
    std::strcpy(_newNode->lastname, lastname);
    _newNode->next = NULL; // Ensure new node's next pointer is NULL

    // Iterator
    Data* prt = head;

    if ((*name != '\0') && (*lastname != '\0')) {
        // Find the last node in the list:
        if (*head->name == '\0') { // Special Case: list is empty
            std::strcpy(head->name, name);
            std::strcpy(head->lastname, lastname);
            head->next = NULL;
        } else {
            // Traverse the list to find the last node
            while (prt->next != NULL) {
                prt = prt->next;
            }
            // Link the new node to the end of the list
            prt->next = _newNode;
        }
    }
}
