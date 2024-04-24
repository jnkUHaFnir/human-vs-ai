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

void print(struct Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

void del_p(struct Node* current)
{
    if (current == NULL)
    {
        return;
    }

    if (current->next != NULL)
    {
        struct Node* temp = current->next;
        current->data = temp->data;
        current->next = temp->next;
        free(temp);
    }
    else
    {
        struct Node* temp = current;
        free(temp);
        current = NULL; // This line should be removed as it does not affect the original pointer in main
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

    del_p(head->next->next->next);
    
    cout << endl;
    print(head);

    return 0;
}
