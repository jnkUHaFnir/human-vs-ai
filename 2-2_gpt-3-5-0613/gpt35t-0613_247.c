#include <stdio.h>


struct mychar {
    char value;
    struct mychar *nextPtr;
};

typedef struct mychar Mychar;


void instructions();
void append(Mychar **, char );
void printlist(Mychar *);


int main(){
    instructions();

    Mychar *startPtr = NULL;

    unsigned int choice;
    char newchar;
    do {
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("\nWrite the character you want to add.");
                printf("\n> ");
                fflush(stdout); // Flush the output buffer

                scanf(" %c", &newchar);
                append(&startPtr, newchar);
                printlist(startPtr);
                break;
            case 2:
                break;
            default:
                printf("\nError, try again.\n");
                //main();
                instructions();
                break;
        }
    } while (choice!=3);
    printf("\n\nEnd of run.\n");
}


void instructions(){
    printf("\nSelect operation. 1 to add, 2 to remove, 3 to exit.");
    printf("\n> ");
}


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

}


void printlist(Mychar *currentPtr){
    printf("\n\nCurrent list:\n");
    fflush(stdout); // Flush the output buffer

    while (currentPtr!=NULL){
        printf("%c", currentPtr->value);
        currentPtr = currentPtr->nextPtr;
    }
}
