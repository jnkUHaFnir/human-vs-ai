    // checking the validity of the cards
    int unmatchedCount = 0; 
    for (int i = 0; i < max; i++) { 

        int match = 0;
        for (int j = 0; j < max; j++) { 
            // compare each array pair
            if (strcmp(stringcard[i], reds[j]) == 0) { 
                match = 1; 
                break;
            }
        }

        if (!match) { 
            unmatchedCount++;
            printf("%s not matched in input.\n", stringcard[i]);
        }
    }

    if (unmatchedCount > 0) {
        printf("Input doesn't contain all the valid cards.\n");
        return 1;  // return error
    }

    printf("All cards are valid!\n");
