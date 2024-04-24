int main(int argc, char* argv[]) {
    srand(time(NULL));
    secret_nr = (rand() % upper_bound) + 1;

    printf("Guess the number between %d and %d:\n", lower_bound, upper_bound);
    while (1) {
        if (scanf("%d", &guess) == 1) {
            check_input();
            if (guess == secret_nr) {
                break;
            }
        }
        else {
            printf("Invalid input! Only integer values are allowed!\n");
            while(getchar() != '\n'); // Clear input buffer
        }
    }

    return 0;
}
