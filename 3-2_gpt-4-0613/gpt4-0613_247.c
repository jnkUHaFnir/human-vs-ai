void append(Mychar **sPtr, char newvalue){
    Mychar *newlinkPtr = calloc (1, sizeof(Mychar));
    newlinkPtr->value = newvalue;
    newlinkPtr->nextPtr = NULL;

    Mychar *previousPtr = NULL;
    Mychar *currentPtr = *sPtr;

    while(currentPtr!=NULL && newvalue > currentPtr->value){
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    if (previousPtr){
        previousPtr->nextPtr = newlinkPtr;
        newlinkPtr->nextPtr = currentPtr;
    } else {
        *sPtr = newlinkPtr;
    }
    fflush(stdout);
}


void printlist(Mychar *currentPtr){
    printf("\n\nCurrent list:\n");
    while (currentPtr!=NULL){
        printf("%c", currentPtr->value);
        currentPtr = currentPtr->nextPtr;
    }
    fflush(stdout);
}
scanf("%d",&choice);
scanf("%*c");  // consumes the newline character
