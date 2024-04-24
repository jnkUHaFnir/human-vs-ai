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
      while(ptr->next != NULL && ptr->next->value == head->value)
      {
          temp = ptr;
          ptr = ptr->next;
      }
      
      if (ptr->value == head->value) {
          // Remove the right-most instance of the head value
          if (temp == NULL) { // Head is the node to be removed
              head = ptr->next;
          } else {
              temp->next = ptr->next;
          }
          
          free(ptr);
          return val;
      }
  }
}
