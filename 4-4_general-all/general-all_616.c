#include <stdio.h>
#include <stdlib.h>

struct node {
    double value;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node* create_new_node(double value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void insertNode(double value) {
    struct node *new_node = create_new_node(value);

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        struct node *temp = head;
        struct node *prev = NULL;

        while (temp != NULL && value > temp->value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL && value == temp->value) {
            if (temp == head) {
                new_node->next = temp;
                head = new_node;
            } else {
                prev->next = new_node;
                new_node->next = temp;
            }
        } else {
            if (temp == NULL) {
                tail->next = new_node;
                tail = new_node;
            } else {
                if (temp == head) {
                    new_node->next = temp;
                    head = new_node;
                } else {
                    prev->next = new_node;
                    new_node->next = temp;
                }
            }
        }
    }
}

double removeLowestValue() {
    if (head == NULL) {
        fprintf(stderr, "Linked list is empty.\n");
        exit(1);
    }

    double lowest_val = head->value;
    struct node *prev = NULL;
    struct node *curr = head;

    while (curr != NULL) {
        if (curr->value <= lowest_val) {
            lowest_val = curr->value;
        }
        prev = curr;
        curr = curr->next;
    }

    struct node *temp = NULL;
    prev = NULL;
    curr = head;
    while (curr != NULL) {
        if (curr->value == lowest_val) {
            temp = prev;
        }
        prev = curr;
        curr = curr->next;
    }

    if (temp != NULL) {
        struct node *to_free = temp->next;
        if (to_free == tail) {
            tail = temp;
        }
        temp->next = to_free->next;
        double val = to_free->value;
        free(to_free);
        return val;
    }

    return 0; // No match found for the lowest value
}

int main() {
    insertNode(18.0);
    insertNode(13.0);
    insertNode(11.0);
    insertNode(11.0);
    insertNode(22.0);

    printf("%lf", removeLowestValue());

    return 0;
}
