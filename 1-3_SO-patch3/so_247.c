    do {
        int c; //for buffer clearence
        instructions(); //move inside the loop, user will be prompted in each cycle
        if(scanf("%d", &choice) == 0){
            while((c = getchar()) != '\n' && c != EOF){} // if input fails clear the buffer
        }
        switch (choice)
        {
        case 1:
            printf("\nWrite the character you want to add.");
            printf("\n> ");
            if(scanf(" %c", &newchar) == 0){ //same
                while((c = getchar()) != '\n' && c != EOF){}
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
        while((c = getchar()) != '\n' && c != EOF){} 
    } while (choice != 3);  