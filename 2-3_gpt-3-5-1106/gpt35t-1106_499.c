int main(int argc, char* argv[]) {
    srand(time(NULL));
    secret_nr = (rand() % upper_bound) + 1;

    printf("Guess the number between %d and %d:\n", lower_bound, upper_bound);
    do {
        while (scanf("%d", &guess) != 1) {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input! Only integer values are allowed!\n");
            printf("Guess the number between %d and %d:\n", lower_bound, upper_bound);
        }
        check_input();
    } while (guess != secret_nr);

    return 0;
}
