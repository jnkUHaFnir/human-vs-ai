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
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void print(struct Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

void del_p(struct Node* head, struct Node* current)
{
    struct Node *temp;
    if (current->next != NULL)
    {
        temp = current->next;
        current->data = temp->data;
        current->next = temp->next;
        free(temp);
    }
    else
    {
        struct Node* temp = head;
        while (temp->next != current)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        free(current);
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
    del_p(head, head->next->next->next);
    print(head);

    return 0;
}
