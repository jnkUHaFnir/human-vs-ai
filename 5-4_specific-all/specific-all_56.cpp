void Append(Data* head, char* name, char* lastname) {
    Data* _newNode = (Data*)malloc(sizeof(Data));
    std::strcpy(_newNode->name, name);
    std::strcpy(_newNode->lastname, lastname);
    
    // Iterator
    Data* prt = head;

    if ((*name != '\0') && (*lastname != '\0')) {
        // Find the last node in the list
        if (head->name[0] == '\0') {
            std::strcpy(head->name, name);
            std::strcpy(head->lastname, lastname);
        } else {
            // Traverse the list to find the last node
            while (prt->next != NULL) {
                prt = prt->next;
            }
            prt->next = _newNode; // Update the last node to point to the new node
        }
    }
}
