void Append(Data* head, char* name, char* lastname) { 
    Data* _newNode = (Data*)malloc(sizeof(Data));
    std::strcpy(_newNode->name, name);
    std::strcpy(_newNode->lastname, lastname);
    // Iterator
    Data* prt = head;
    if ((name != NULL) && (lastname != NULL)) {
        // find the last node in the list:
        // Special Case
        if (head->name == NULL) {
            std::strcpy(head->name, name);
            std::strcpy(head->lastname, lastname);
        } else {
            while (prt->next != NULL) {
                prt = prt->next;
            }
            prt->next = _newNode;
        }
    }
}
