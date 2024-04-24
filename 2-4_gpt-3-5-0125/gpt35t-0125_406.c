char input[100];
fgets(input, sizeof(input), stdin);
if (strlen(input) > 10) {
    printf("Input exceeds maximum length. Please enter a shorter input.\n");
    // Handle the situation accordingly
}
if (strlen(input) > 10) {
    input[10] = '\0'; // Truncate the input at the specified length
}
