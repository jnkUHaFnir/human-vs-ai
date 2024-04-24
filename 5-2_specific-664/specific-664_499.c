if (scanf("%d", &guess) != 1) {
    printf("Invalid input! Only integer values are allowed!\n");
    // Clear the input buffer to prevent infinite loop
    while (getchar() != '\n');
}
else {
    check_input();
}
