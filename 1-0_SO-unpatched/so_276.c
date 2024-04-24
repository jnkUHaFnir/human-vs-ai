    while(1){
        do{
            type = -1;
            printf("Enter 0 for End, 1 for sports car, 2 for midsize, 3 for economy: ");
            scanf("%d\n", &type);        
        } while (type < 0 || type > 3);
        if (type == 0) break;
        // The rest of the stuff here ...
    }