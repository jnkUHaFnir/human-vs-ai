#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void print(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

void del_p(struct Node* current) {
    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->data = temp->data;
        current->next = temp->next;
        free(temp);
    } else {
        free(current);
        current = NULL;
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 4);
    push(&head, 6);
    push(&head, 8);
    print(head);
    cout << endl;
    
    del_p(head->next->next->next);
    cout << endl;
    
    print(head);
    
    return 0;
}
