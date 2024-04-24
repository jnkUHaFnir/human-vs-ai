double removeLowestValue() {
  struct node *prev = NULL;
  struct node *ptr = head;
  double lowestVal = ptr->value;
  struct node *rightMostInstance = NULL;

  while (ptr != NULL) {
    if (ptr->value <= lowestVal) {
      lowestVal = ptr->value;
      rightMostInstance = prev;
    }
    prev = ptr;
    ptr = ptr->next;
  }

  if (rightMostInstance == NULL) {
    // Remove the head
    double removedVal = head->value;
    head = head->next;
    free(ptr);
    return removedVal;
  } else {
    // Remove the right-most instance of the lowest value
    double removedVal = rightMostInstance->next->value;
    struct node *temp = rightMostInstance->next;
    rightMostInstance->next = rightMostInstance->next->next;
    if (temp == tail) {
      tail = rightMostInstance;
    }
    free(temp);
    return removedVal;
  }
}
