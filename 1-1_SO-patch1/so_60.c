    while (nextEl != null) {
    if (strcmp(nextEl->code, code))  {
       product* current->next = nextEl->next;
       free (nextEl);
        return 1;
    }
    else {
       current = nextEl;
       nextEl = nextEl->next;
    }
    }
     return 0;