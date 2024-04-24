double removeLowestValue() {
  struct node *temp = NULL;
  struct node *ptr = head;
  double val = ptr->value;

  if (head == tail) {
    free(head);
    head = NULL;
    tail = NULL;
  } else {
    while (ptr->next != NULL) {
      if (ptr->next->value == val) {
        temp = ptr;
      }
      ptr = ptr->next;
    }

    if (temp == NULL) {
      // No duplicate value found
      return -1.0; // Or any other suitable value indicating failure
    } else {
      if (temp->next == tail) {
        free(tail);
        temp->next = NULL;
        tail = temp;
      } else {
        struct node *toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
      }

      return val;
    }
  }
}
