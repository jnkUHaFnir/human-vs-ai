double removeLowestValue() {
  struct node *temp = NULL;
  struct node *ptr = head;
  double val = ptr->value;
  
  if(head == NULL) {
    printf("List is empty\n");
    return -1;
  }

  while(ptr != NULL && ptr->next != NULL) {
    if(ptr->next->value == val) {
      temp = ptr;
    }
    ptr = ptr->next;
  }

  if(temp == NULL) {
    printf("No instance of the lowest value found to remove\n");
    return -1;
  }

  ptr = temp->next;
  temp->next = ptr->next;

  free(ptr);

  return val;
}
int main() {
  insertNode(18.0);
  insertNode(13.0);
  insertNode(11.0);
  insertNode(11.0);
  insertNode(22.0);

  double removedValue = removeLowestValue();
  if(removedValue != -1) {
    printf("Removed value: %.1f\n", removedValue);
  }

  return 0;
}
