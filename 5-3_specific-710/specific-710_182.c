void swap(struct student *node1) {
  if(node1 == NULL || node1->next == NULL) {
    return; // Cannot swap if node1 or its next node is NULL
  }

  struct student *node2 = node1->next;

  // Adjust the 'next' pointers
  if(node1->previous != NULL) {
    node1->previous->next = node2;
  } else {
    first = node2;
  }
  if(node2->next != NULL) {
    node2->next->previous = node1;
  } else {
    last = node1;
  }
  node1->next = node2->next;
  node2->next = node1;

  // Adjust the 'previous' pointers
  node2->previous = node1->previous;
  node1->previous = node2;
}
void sort(void) {
  int swapped;
  struct student *ptr = NULL;

  if(first == NULL) {
    return; // Empty list
  }

  do {
    swapped = 0;
    ptr = first;
    
    while(ptr->next != NULL) {
      if(strcmp(ptr->Nachname, ptr->next->Nachname) > 0) {
        swap(ptr);
        swapped = 1;
      }
      ptr = ptr->next;
    }
  } while(swapped);
}
