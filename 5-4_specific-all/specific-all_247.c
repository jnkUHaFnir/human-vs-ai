void instructions(){
    printf("\nSelect operation. 1 to add, 2 to remove, 3 to exit.");
    printf("\n> ");
    fflush(stdout); // flush the output buffer
}

void printlist(Mychar *currentPtr){
    printf("\n\nCurrent list:\n");
    while (currentPtr!=NULL){
        printf("%c", currentPtr->value);
        currentPtr = currentPtr->nextPtr;
    }
    fflush(stdout); // flush the output buffer
}
