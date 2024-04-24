#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

// Utility function to add a new node with the given value at the head of the linked list
void push(struct Node** head, int val) {
    struct Node* newNode = new Node;
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

// Print the linked list
void print(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Delete a node with the given pointer from the linked list
void del_p(struct Node** head, struct Node* ptrToDel) {
    if (*head == NULL || ptrToDel == NULL) {
        return;
    }

    if (*head == ptrToDel) {
        *head = (*head)->next;
        delete ptrToDel;
        return;
    }

    struct Node* prev = NULL;
    struct Node* curr = *head;
    while (curr != NULL && curr != ptrToDel) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        return; // Not found in the list
    }

    prev->next = curr->next;
    delete curr;
}

int main() {
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 4);
    push(&head, 6);
    push(&head, 8);
    print(head);
    del_p(&head, head->next->next->next);
    cout << endl;
    print(head);
    return 0;
}
