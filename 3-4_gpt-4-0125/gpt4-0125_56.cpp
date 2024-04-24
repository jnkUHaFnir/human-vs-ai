void Append(Data* head, const char* name, const char* lastname) { 
    if (name[0] == '\0' || lastname[0] == '\0') return; // If names are empty, do nothing.

    // Create a new node with safer dynamic memory allocation.
    Data* _newNode = new Data();
    strncpy(_newNode->name, name, NAME_SIZE - 1); // Assuming NAME_SIZE is the buffer size.
    _newNode->name[NAME_SIZE - 1] = '\0'; // Ensure null-termination.
    strncpy(_newNode->lastname, lastname, LASTNAME_SIZE - 1); // Assuming LASTNAME_SIZE is the buffer size.
    _newNode->lastname[LASTNAME_SIZE - 1] = '\0'; // Ensure null-termination.
    _newNode->next = nullptr; // Initialize next to nullptr.

    if (head->name[0] == '\0') { // Special case: head is empty.
        std::strcpy(head->name, name);
        std::strcpy(head->lastname, lastname);
    } else {
        Data* ptr = head;
        while (ptr->next != nullptr) { // Find the last node.
            ptr = ptr->next;
        }
        ptr->next = _newNode; // Append the new node as last node's next.
    }
}
