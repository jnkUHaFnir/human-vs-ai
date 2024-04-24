void printlist(Mychar *currentPtr){
    printf("\n\nCurrent list:\n");
    fflush(stdout); // Flush the output buffer

    while (currentPtr!=NULL){
        printf("%c", currentPtr->value);
        currentPtr = currentPtr->nextPtr;
    }
}
