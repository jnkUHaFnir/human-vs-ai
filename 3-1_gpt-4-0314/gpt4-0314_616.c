#include <stdio.h>
#include <stdlib.h>

struct node {
  double value;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *create_new_node(double value) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

void insertNode(double value) {
  struct node *new_node = create_new_node(value);
  struct node *temp = head;
  struct node *prev = NULL;

  if (head == NULL) {
    head = new_node;
    tail = new_node;
  } else {
    while (value > temp->value && temp->next != NULL) {
      prev = temp;
      temp = temp->next;
    }

    if (value < temp->value || value == temp->value) {
      new_node->next = temp;
      if (prev == NULL) {
        head = new_node;
      } else {
        prev->next = new_node;
      }
    } else if (value > temp->value) {
      temp->next = new_node;
      tail = new_node;
    }
  }
}

double removeLowestValue() {
  struct node *temp;
  struct node *ptr = head;
  double val = ptr->value;

  if (head == tail) {
    free(head);
    head = NULL;
    tail = NULL;
  } else {
    while (ptr->value == ptr->next->value) {
      temp = ptr;
      ptr = ptr->next;
      val = ptr->value;
    }
    temp->next = ptr->next;
    free(ptr);

    return val;
  }
}

int main() {
  insertNode(18.0);
  insertNode(13.0);
  insertNode(11.0);
  insertNode(11.0);
  insertNode(22.0);

  printf("%lf\n", removeLowestValue());

  return 0;
}
