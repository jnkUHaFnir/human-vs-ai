...
int main(){
    instructions();

    Mychar *startPtr = NULL;

    unsigned int choice;
    char newchar;
    do {
        scanf("%d",&choice);
        // Consume the newline character from the buffer
        getchar();

        switch (choice) {
            case 1:
                printf("\nWrite the character you want to add.");
                printf("\n> ");
                scanf(" %c", &newchar);

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
    } while (choice!=3);
    printf("\n\nEnd of run.\n");
}
...
