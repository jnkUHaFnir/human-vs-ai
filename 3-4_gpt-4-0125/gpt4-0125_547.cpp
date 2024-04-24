if (scanf("%d", &i) != 1) {
    while (getchar() != '\n'); // Clear the buffer up to a newline or EOF
}
if (!(cin >> i)) {
    cin.clear(); // Clear the error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip bad input
}
