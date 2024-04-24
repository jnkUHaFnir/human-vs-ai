void swap(struct student *pointer) {
  struct student *pointer1, *pointer2, *pointer3, *temp;
  pointer1 = pointer->previous;
  pointer2 = pointer->next;
  pointer3 = pointer2->next;

  if(pointer1 != NULL)
    pointer1->next = pointer2;
  if(pointer3 != NULL)
    pointer3->previous = pointer;

  pointer->previous = pointer2;
  pointer2->next = pointer;
  pointer2->previous = pointer1;
  pointer->next = pointer3;

  if(pointer == first)
    first = pointer2;
  if(pointer2 == last)
    last = pointer;
}
void sort(void) {
  struct student *pointer1, *pointer2;
  int swapped = 1;
  
  if(first == NULL)
    return;

  while(swapped) {
    swapped = 0;
    pointer1 = first;

    while(pointer1->next != NULL) {
      pointer2 = pointer1->next;
      if(strcmp(pointer1->Nachname, pointer2->Nachname) > 0) {
        swap(pointer1);
        swapped = 1;
      }
      else {
        pointer1 = pointer2;
      }
    }
  }
}
