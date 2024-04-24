while (1) {
    if (fgets(bnumber, 10, stdin) == NULL) {
        // Handle error or EOF if necessary
        break;
    }
    
    len = strlen(bnumber);
    if (bnumber[len - 1] == '\n') {
        bnumber[len - 1] = '\0';
    }

    // Check if the input is "q" to quit the program
    if (strcmp(bnumber, STOP) == 0) {
        printf("Goodbye!\n");
        break;
    }
    
    binaryreturn = convertbinary(bnumber);
    printf("%d\n", binaryreturn); 
    printf("Enter binary byte or type q to quit:\n");
}

// ...
bnumber = (char *) malloc(10 * sizeof(char));
