#include <stdio.h>
#include <stdlib.h> // Include for calloc

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
                printf("\nWrite the character you want to add.\n> ");
                scanf(" %c", &newchar);
                // Clear input buffer
                while ((getchar()) != '\n');
                append(&startPtr, newchar);
                printlist(startPtr);
                break;
            case 2:
                break;
            default:
                printf("\nError, try again.\n");
                instructions();
                break;
        }
    } while (choice != 3);

    printf("\n\nEnd of run.\n");
    return 0;
}

void instructions(){
    printf("\nSelect operation. 1 to add, 2 to remove, 3 to exit.\n> ");
}

void append(Mychar **sPtr, char newvalue){
    Mychar *newlinkPtr = calloc(1, sizeof(Mychar));
    newlinkPtr->value = newvalue;
    newlinkPtr->nextPtr = NULL;

    Mychar *previousPtr = NULL;
    Mychar *currentPtr = *sPtr;

    while(currentPtr != NULL && newvalue > currentPtr->value){
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
    while (currentPtr != NULL){
        printf("%c", currentPtr->value);
        currentPtr = currentPtr->nextPtr;
    }
}
