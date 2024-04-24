double removeLowestValue() {
  struct node *temp = NULL;
  struct node *prev = NULL;
  struct node *ptr = head;
  double val = ptr->value;

  if(head == NULL) {
      printf("List is empty\n");
      return -1; // Return an error value
  }

  while(ptr->next != NULL) {
      if(ptr->value == head->value) {
          temp = prev; // Save the node before the potential node to be deleted
      }
      prev = ptr;
      ptr = ptr->next;
  }

  // Handle the case when the head itself is the only node in the list
  if(temp == NULL) {
      temp = head;
      head = head->next;
  } else if(temp->next != NULL) {
      temp->next = temp->next->next;
  }

  free(ptr);
  return val;
}
