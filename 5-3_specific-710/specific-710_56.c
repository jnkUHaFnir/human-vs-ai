void Append(Data* head, char* name, char* lastname) { 
    Data* _newNode = (Data*)malloc(sizeof(Data));
    std::strcpy(_newNode->name, name);
    std::strcpy(_newNode->lastname, lastname);
    _newNode->next = NULL; // Ensure the next pointer of the new node is NULL

    if (*name != '\0' && *lastname != '\0') {
        // Special Case: empty list
        if (head->name[0] == '\0') {
            std::strcpy(head->name, name);
            std::strcpy(head->lastname, lastname);
            head->next = NULL;
        } else {
            Data* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = _newNode;
        }
    }
}
