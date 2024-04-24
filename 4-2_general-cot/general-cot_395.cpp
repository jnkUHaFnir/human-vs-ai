#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void del_p(struct Node* current)
{
    struct Node* temp;
    struct Node* prev = NULL;

    if (current == NULL || current->next == NULL) {
        // Edge case: If the node to be deleted is NULL or the last node
        free(current);
        if (prev != NULL) {
            prev->next = NULL;
        }
        current = NULL;
        return;
    }

    while (current->next != NULL) {
        current->data = current->next->data;
        prev = current;
        current = current->next;
    }

    free(current);
    if (prev != NULL) {
        prev->next = NULL;
    }
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void print(struct Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 4);
    push(&head, 6);
    push(&head, 8);

    cout << "Original List: ";
    print(head);

    cout << endl << "After deleting last node: ";
    del_p(head->next->next->next);
    print(head);

    return 0;
}
