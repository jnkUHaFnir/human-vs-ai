    printf("Nome: ");
    tmp = getString();
    rub[idx].name = (char *) malloc(strlen(tmp) + 1); // Correct allocation
    strcpy(rub[idx].name, tmp); // Correct assignment
    free(tmp); // Free tmp since it's copied

    // Do similarly for surname, address, and number
    // Ensure getString is called for each to capture new input
    // Remember to free the allocated space for tmp after each use
