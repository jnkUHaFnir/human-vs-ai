    struct student {
        char Vorname[51];
        char Nachname[51];
        int MatNr;
        char Adresse[51];
        int Kurse;
        struct student *next;
        struct student *previous;
    };
    
    struct student *first = NULL;
    struct student *last = NULL;
    
    struct student *msort(struct student *np) {
        struct student *p1, *p2, **pp;
        /* trivial lists are sorted */
        if (np == NULL || np->next == NULL)
            return np;
        /* split the list at mid-point using 2 finger method */
        for (p1 = p2 = np; p2 && p2->next; p2 = p2->next->next)
            p1 = p1->next;
        /* split the list at mid-point */
        p2 = p1->next;
        p1->next = NULL;
        p1 = np;
        /* sort the sublists recursively */
        p1 = msort(p1);
        p2 = msort(p2);
        /* merge the sorted lists */
        pp = &np;
        for (;;) {
            if (strcmp(p1->Nachname, p2->Nachname) <= 0) {
                *pp = p1;
                pp = &p1->next;
                p1 = p1->next;
                if (p1 == NULL) {
                    *pp = p2;
                    break;
                }
            } else {
                *pp = p2;
                pp = &p2->next;
                p2 = p2->next;
                if (p2 == NULL) {
                    *pp = p1;
                    break;
                }
            }
        }
        return np;
    }
    
    void sort(void) {
        struct student *p1, *p2;
        /* sort the list as a singly linked list */
        first = msort(first);
        /* reconstruct the backlinks */
        p1 = NULL;
        for (p2 = first; p2; p2 = p2->next) {
            p2->last = p1;
            p1 = p2;
        }
        last = p1;
    }