while ((int*)prt->next != NULL) {
    prt = prt->next;
}
prt = _newNode;
while (prt->next != NULL) {
    prt = prt->next;
}
prt->next = _newNode;
