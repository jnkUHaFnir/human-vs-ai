while ((int*)ptr->next != NULL) {
    ptr = ptr->next;
}
ptr = _newNode;
ptr->next = _newNode;
void Append(Data* head, char* name, char* lastname) {
    Data* _newNode = (Data*)malloc(sizeof(Data));
    std::strcpy(_newNode->name, name);
    std::strcpy(_newNode->lastname, lastname);
    _newNode->next = NULL; // Don't forget to initialize the next pointer of the new node to NULL

    // Iterator
    Data* ptr = head;
    if ((*name != '\0') && (*lastname != '\0')) {
        // find the last node in the list:
        // Special Case
        if (*head->name == '\0') {
            std::strcpy(head->name, name);
            std::strcpy(head->lastname, lastname);
        } else {
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = _newNode;
        }
    }
}
