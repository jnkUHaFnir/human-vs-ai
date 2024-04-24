    double removeLowestValue() {
      if (head == NULL)
        return 0; /* ???? */
      else {
        node * ptr = head;
        node * previous = 0; /* the cell before the cell to remove */
        
        while ((ptr->next != NULL) && (ptr->value == ptr->next->value)) {
          previous = ptr;
          ptr = ptr->next;
        }
        
        /* ptr is now the cell to remove */
        
        double val = ptr->value;
        
        if (ptr == head) {
          /* remove the first cell */
          ptr = head->next;
          free(head);
          head = ptr;
          if (head == NULL)
            /* the list is empty */
            tail = NULL;
        }
        else if (ptr->next == NULL) {
          /* all the values are the same in the list
             ptr is the last cell */
          free(ptr);
          /* previous is now the last cell */
          previous->next = 0;
          tail = previous;
        }
        else {
          /* ptr is not the first nor the last cell */
          previous->next = ptr->next;
          free(ptr);
        }
        
        return val;
      }
    }