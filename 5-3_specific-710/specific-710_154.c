char pop(STACK *sptr) {
    if (isEmpty(sptr) == 0)
        return sptr->s[sptr->top--]; // Update the top index after popping
    else
        return '$';
}
