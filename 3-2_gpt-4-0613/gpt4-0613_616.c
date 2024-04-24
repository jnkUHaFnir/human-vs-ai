printf("%f", removeLowestValue());
struct node{
    double value;
    node *next;
};

node * head = NULL;
node * tail = NULL;

node * create_new_node(double value)
{
    node * temp = (node*)malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

void insertNode(double value) {
  node *new_node = create_new_node(value);
  
  if (head == NULL || head->value > value) {
    new_node->next = head;
    head = new_node;
    if(tail == NULL)
        tail = new_node;
  } 
  else {
    node *current = head;
    while (current->next!=NULL && current->next->value <= value)
    {
        current = current->next;
    }
    if (current == tail)
    {
        tail = new_node;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

double removeLowestValue() {
  node *temp;
  node *ptr = head;
  double val = ptr->value;
  if(head == tail)
  {
      free(head);
      head = NULL;
      tail = NULL;
  }
  else
  {
      while(ptr->next && ptr->value == ptr->next->value)
      {
          temp = ptr;
          ptr = ptr->next;
          val = ptr->value;
      }
      temp->next = ptr->next;
      free(ptr);
      return val;
  }
  return -1; //return some value indicating list was empty.
}

int main() {
    insertNode(18.0);
    insertNode(13.0);
    insertNode(11.0);
    insertNode(11.0);
    insertNode(22.0);
    printf("%f", removeLowestValue());

    return 0;
}
