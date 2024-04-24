_newNode->next = NULL;
prt->next = _newNode;
void Append(Data* head, char* name, char* lastname) {
    Data* _newNode = (Data*)malloc(sizeof(Data));
    std::strcpy(_newNode->name, name);
    std::strcpy(_newNode->lastname, lastname);
    _newNode->next = NULL; // Initialize the next pointer of the new node to NULL

    Data* prt = head;
    if ((*name != '\0') && (*lastname != '\0')) {
        // Find the last node in the list:
        // Special case
        if (*head->name == '\0') {
            std::strcpy(head->name, name);
            std::strcpy(head->lastname, lastname);
        } else {
            while (prt->next != NULL) {
                prt = prt->next;
            }
            prt->next = _newNode; // Set the next pointer of the last node to the new node
        }
    }
}
