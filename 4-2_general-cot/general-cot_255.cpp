#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

void del_p(struct Node* current) {
    if (current == NULL || current->next == NULL) {
        // If the node to be deleted is NULL or the last node, return
        return;
    }

    struct Node* temp = current->next;
    current->data = temp->data;
    current->next = temp->next;
    delete temp; // Use delete instead of free for C++

}

int main() {
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 4);
    push(&head, 6);
    push(&head, 8);
    print(head);
    del_p(head->next->next->next);
    cout << endl;
    print(head);
    return 0;
}
