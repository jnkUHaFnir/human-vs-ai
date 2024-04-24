    double removeLowestValue() {
      if ((head == tail) || (head->next == 0)) /* check head->next because not sure what tail is */
      {
          free(head);
          head = NULL;
          tail = NULL;
          
          return 0; /* ????? */
      }
      else {
          node * ptr = head;
          
          while((ptr->next != 0) && (ptr->value == ptr->next->value))
          {
              ptr = ptr->next;
          }
          
          if (ptr->next == 0) {
            /* all the values are the same in the list */
            ptr = head;
          }
              
          double val = ptr->value;
          node * removed = ptr->next;
          
          ptr->value = removed->value;
          ptr->next = removed->next;
          
          free(removed);
    
          return val;
      }
    }