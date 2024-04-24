#define ROWS 3
#define COLS 4

int numbers[ROWS][COLS];
int rows = 3;
int cols = 4;

int **numbers;

numbers = (int **)malloc(rows * sizeof(int *));
for (int i = 0; i < rows; i++) {
    numbers[i] = (int *)malloc(cols * sizeof(int));
}
