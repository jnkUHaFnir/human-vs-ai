#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void del_p(struct Node* prev, struct Node* current)
{
    if (current->next != NULL)
    {
        struct Node* temp = current->next;
        current->data = temp->data;
        current->next = temp->next;
        free(temp);
    }
    else
    {
        free(current);
        prev->next = NULL; // Update previous node's next pointer
    }
}

int main()
{
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 4);
    push(&head, 6);
    push(&head, 8);
    
    print(head);
    cout << endl;

    struct Node* current = head->next->next->next;
    struct Node* prev = head->next->next; // Get the previous node
    del_p(prev, current);

    print(head);
    
    return 0;
}
