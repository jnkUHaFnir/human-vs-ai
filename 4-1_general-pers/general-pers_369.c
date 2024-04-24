#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Foo {
    int fieldint;
    char fieldchar;
    float fieldfloat;
};

// Function prototypes
struct Foo **initialize(int N);
void sort(int N, struct Foo **array);
int count(int N, struct Foo **array, char X);
void deleteArray(int N, struct Foo **array);

int main() {
    // Read N and X from the input file
    FILE *file = fopen("inlab01.txt", "r");
    int number;
    char letter;
    if (file == NULL) {
        printf("Error opening file");
        exit(-1);
    }
    fscanf(file, "%d %c", &number, &letter);
    fclose(file);

    // Initialize the array
    struct Foo **arr = initialize(number);

    // Sorting the array based on fieldint
    sort(number, arr);

    // Counting occurrences of letter X in fieldchar
    int countX = count(number, arr, letter);
    printf("Count of letter '%c': %d\n", letter, countX);

    // Printing the first 20 structures
    for (int i = 0; i < number && i < 20; i++) {
        printf("Structure %d:\nfield int: %d\nfield char: %c\nfield float: %f\n\n", i + 1, arr[i]->fieldint, arr[i]->fieldchar, arr[i]->fieldfloat);
    }

    // Deleting the allocated memory
    deleteArray(number, arr);

    return 0;
}

struct Foo **initialize(int N) {
    struct Foo **array = malloc(sizeof(struct Foo *) * N);
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        array[i] = malloc(sizeof(struct Foo));
        array[i]->fieldint = rand();
        array[i]->fieldchar = (char)(rand() % 24) + 'A'; // Use ASCII values for letters
        array[i]->fieldfloat = i;
    }

    return array;
}

void sort(int N, struct Foo **array) {
    struct Foo *temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (array[j]->fieldint > array[j + 1]->fieldint) {
                // Swap the structures
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int count(int N, struct Foo **array, char X) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (array[i]->fieldchar == X) {
            counter++;
        }
    }
    return counter;
}

void deleteArray(int N, struct Foo **array) {
    for (int i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);
}
