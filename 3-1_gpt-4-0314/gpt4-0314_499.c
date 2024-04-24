int main(int argc, char* argv[]) {
    srand(time(NULL));
    secret_nr = (rand() % upper_bound) + 1;

    printf("Guess the number between %d and %d:\n", lower_bound, upper_bound);
    do {
        if (scanf("%d", &guess)) {
            check_input();
        }
        else {
            printf("Invalid input! Only integer values are allowed!\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);  // Clear the input buffer
        }
    } while (guess != secret_nr);

    return 0;
}
