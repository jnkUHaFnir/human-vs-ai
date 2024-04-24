#define ROWS 3
#define COLS 4

int numbers[ROWS][COLS];

// Initialize the global 2D array
void initializeArray() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            numbers[i][j] = 0;
        }
    }
}

// Access and modify elements in the global 2D array
void accessArray() {
    numbers[1][2] = 10;
}

// Example usage
int main() {
    initializeArray();
    accessArray();

    // Accessing and printing elements of the global 2D array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }

    return 0;
}
