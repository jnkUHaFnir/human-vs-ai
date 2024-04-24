void swap(struct student *pointer) {
  struct student *pointer1, *pointer2, *pointer3;

  pointer1 = pointer->previous;
  pointer2 = pointer->next;
  pointer3 = pointer2->next;

  if (pointer1 != NULL) {
    pointer1->next = pointer2;
  }
  pointer2->previous = pointer1;
  pointer2->next = pointer;
  pointer->previous = pointer2;
  pointer->next = pointer3;
  if (pointer3 != NULL) {
    pointer3->previous = pointer;
  }
}
void sort(void) {
  int swapped;
  struct student *ptr;
  struct student *lptr = NULL;

  // Check if the list is empty
  if (first == NULL) {
    return;
  }

  do {
    swapped = 0;
    ptr = first;

    while (ptr->next != lptr) {
      if (strcmp(ptr->Nachname, ptr->next->Nachname) > 0) {
        swap(ptr);

        swapped = 1;
      }
      ptr = ptr->next;
    }
    lptr = ptr;
  } while (swapped);
}
