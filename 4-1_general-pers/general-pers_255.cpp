#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void del_p(struct Node* current) {
    if (current == NULL || current->next == NULL) {
        return;
    }

    struct Node* temp = current->next;
    current->data = temp->data;
    current->next = temp->next;
    free(temp);
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
    
    print(head);

    return 0;
}
