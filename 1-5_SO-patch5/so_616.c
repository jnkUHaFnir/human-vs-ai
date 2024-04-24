    double removeLowestValue() {
      if (head == NULL)
        return 0; /* ???? */
      else if (head == tail)
      {
          free(head);
          head = NULL;
          tail = NULL;
          
          return 0; /* ????? */
      }
      else {
          node * ptr = head;
          
          while((ptr->next != NULL) && (ptr->value == ptr->next->value))
          {
              ptr = ptr->next;
          }
          
          if (ptr->next == NULL) {
            /* all the values are the same in the list */
            ptr = head;
          }
              
          double val = ptr->value;
          node * removed = ptr->next;
          
          ptr->value = removed->value;
          ptr->next = removed->next;
          
          free(removed);
          
          if (ptr->next == NULL)
            tail = ptr;
    
          return val;
      }
    }