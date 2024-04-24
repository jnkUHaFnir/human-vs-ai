#include <cstdlib>
#include <cstring>

struct Data {
    char name[100];
    char lastname[100];
    Data* next;
};

void Append(Data* head, char* name, char* lastname) {
    Data* _newNode = (Data*)malloc(sizeof(Data));
    std::strcpy(_newNode->name, name);
    std::strcpy(_newNode->lastname, lastname);
    _newNode->next = NULL; // Initialize next pointer for the new node

    Data* prt = head;
    
    if ((*name != '\0') && (*lastname != '\0')) {
        if (*head->name == '\0') {
            std::strcpy(head->name, name);
            std::strcpy(head->lastname, lastname);
        } else {
            while (prt->next != NULL) {
                prt = prt->next;
            }
            prt->next = _newNode; // Link the last node to the new node
        }
    }
}
