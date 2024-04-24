double removeLowestValue() {
  struct node *temp;
  struct node *ptr = head;
  double val = ptr->value;
  if(head == tail)
  {
      free(head);
      head = NULL;
      tail = NULL;
  }
  else
  {
      while(ptr->value == ptr->next->value)
      {
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

  printf("%f\n", removeLowestValue());

  return 0;
}
