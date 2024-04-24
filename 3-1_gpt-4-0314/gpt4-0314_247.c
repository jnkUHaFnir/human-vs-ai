void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
case 1:
    clear_input_buffer(); // Add this line.
    printf("\nWrite the character you want to add.");
    printf("\n> ");
    scanf(" %c", &newchar);
    append(&startPtr, newchar);
    printlist(startPtr);
    break;
