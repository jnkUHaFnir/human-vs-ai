#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void del_p(Node* current)
{
    if (current == NULL || current->next == NULL)
    {
        return;
    }
    
    Node* temp = current->next;
    current->data = temp->data;
    current->next = temp->next;
    delete temp;
}

int main()
{
    Node* head = NULL;
    push(&head, 1);
    push(&head, 4);
    push(&head, 6);
    push(&head, 8);
    
    cout << "Original list: ";
    print(head);
    
    del_p(head->next->next->next);
    
    cout << endl << "List after deletion: ";
    print(head);
    
    return 0;
}
