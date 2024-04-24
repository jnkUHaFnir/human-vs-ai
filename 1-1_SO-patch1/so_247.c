void clear_stdin() { //stdin buffer clearing function 
    int c;
    while ((c = getchar()) != '\n' && c != EOF){}
}
    do {
        instructions(); //move inside the loop, user will be prompted in each cycle
        if (scanf("%d", &choice) == 0) {
            clear_stdin(); // if input fails clear the buffer
        }
        switch (choice) {
        case 1:
            clear_stdin(); // clear the buffer for 1hjh type input
            printf("\nWrite the character you want to add.");
            printf("\n> ");
            if (scanf(" %c", &newchar) == 0) { //same
                clear_stdin();
            }
            append(&startPtr, newchar);
            printlist(startPtr);
            break;
        case 2:
            break;
        case 3:
            printf("\n\nEnd of run.\n"); //if you dont have a case default will catch 3
            break;
        default:
            printf("\nError, try again.\n");
            break;
        }
        //clear excess characters potencialy present in the buffer
        clear_stdin();
    } while (choice != 3);