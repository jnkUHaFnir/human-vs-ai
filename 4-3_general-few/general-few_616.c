double removeLowestValue() {
  struct node *temp = head;
  struct node *ptr = head->next;
  double val = ptr->value;

  while (ptr != NULL) {
    if (ptr->value <= val) {
      val = ptr->value;
      temp = ptr;
    }
    ptr = ptr->next;
  }

  // Find the right-most instance of the lowest value
  while (temp->next != NULL && temp->next->value == val) {
    temp = temp->next;
  }

  if (temp == head) {
    head = temp->next;
  } else {
    struct node *prev = head;
    while (prev->next != temp) {
      prev = prev->next;
    }
    prev->next = temp->next;
  }

  free(temp);
  return val;
}
