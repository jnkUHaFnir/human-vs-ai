while (prt->next != NULL) {
    prt = prt->next;
}
prt->next = _newNode;
_newNode->next = NULL;
