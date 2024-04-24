do {
    if (scanf("%d", &guess) != 1) {
        printf("Invalid input! Only integer values are allowed!\n");
        while (getchar() != '\n'); // Clear the input buffer (consume invalid input)
    } else {
        check_input();
    }
} while (guess != secret_nr);
