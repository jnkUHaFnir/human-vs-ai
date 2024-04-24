#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> // Note: conio.h is not standard C, and getch() is specific to some compilers.

struct Foo {
    int fieldint;
    char fieldchar;
    float fieldfloat;
};

struct Foo** initialize(int N);
void sort(int N, struct Foo **array);
int count(int N, struct Foo **array, char X);
void deleting(int N, struct Foo ***array);

int main() {
    // Reading the number N and the letter to find from the .txt file:
    FILE *file = fopen("inlab01.txt", "r");
    int number;
    char letter; // Changed to a single char
    if (file == NULL) {
        printf("Error opening file\n");
        exit(-1);
    }
    if (fscanf(file, "%d %c", &number, &letter) != 2) { // Ensure both items are read
        printf("Error reading data\n");
        exit(-1);
    }
    fclose(file);

    // Creating the array
    struct Foo **arr = initialize(number); // Corrected type

    // Sorting
    sort(number, arr);

    // Counting how many times the given letter appears
    int letterCount = count(number, arr, letter);
    printf("The letter %c appears %d time(s).\n", letter, letterCount);

    // Printing the first 20 (or fewer) structures
    int limit = (number < 20) ? number : 20;
    for (int i = 0; i < limit; i++) {
        printf("Structure %d:\nfield int: %d\nfield char: %c\nfield float: %f\n\n", i + 1, arr[i]->fieldint, arr[i]->fieldchar, arr[i]->fieldfloat);
    }

    // Deleting
    deleting(number, &arr);

    getch(); // Note: Consider using a portable alternative
    return 0;
}

// Corrected the function to return a pointer to a pointer to Foo (Foo**)
struct Foo** initialize(int N) {
    struct Foo **array = (struct Foo**)malloc(sizeof(struct Foo*) * N);
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        array[i] = (struct Foo*)malloc(sizeof(struct Foo));
        array[i]->fieldint = rand();
        array[i]->fieldchar = (char)((rand() % 24) + 65); // Fixed range for uppercase alphabet letters
        array[i]->fieldfloat = i;
    }

    return array;
}

// Changed parameter type to Foo**
void sort(int N, struct Foo **array) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (array[j]->fieldint > array[j + 1]->fieldint) {
                struct Foo *temp = array[j];
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

void deleting(int N, struct Foo ***array) {
    for (int i = 0; i < N; i++) {
        free((*array)[i]);
    }
    free(*array);
    *array = NULL; // Set pointer to NULL after freeing
}
