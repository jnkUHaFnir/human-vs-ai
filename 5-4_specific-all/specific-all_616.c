double removeLowestValue() {
  struct node *temp = NULL;
  struct node *ptr = head;
  double val = ptr->value;
  
  if (head == tail) {
    free(head);
    head = NULL;
    tail = NULL;
    return val;
  }

  while (ptr->next != NULL && ptr->value == ptr->next->value) {
    temp = ptr;
    ptr = ptr->next;
  }

  if (temp == NULL) {
    // If the head was the only occurrence of the lowest value
    head = head->next;
  } else {
    temp->next = ptr->next;
  }

  free(ptr);
  return val;
}
int main() {
  insertNode(18.0);
  insertNode(13.0);
  insertNode(11.0);
  insertNode(11.0);
  insertNode(22.0);

  printf("%d", (int)removeLowestValue());

  return 0;
}
