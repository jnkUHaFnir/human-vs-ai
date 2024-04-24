#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// structure definition
struct Foo {
    int fieldint;
    char fieldchar;
    float fieldfloat;
};

// function declarations
struct Foo **initialize(int N);
void sort(int N, struct Foo **array);
int count(int N, struct Foo **array, char *X);
void deleting(int N, struct Foo **array);

int main() {
    // read from file
    FILE *file = fopen("inlab01.txt", "r");
    // error handling
    if (file == NULL) {
        printf("Error opening file");
        exit(-1);
    }
    
    int number;
    char letter;
    fscanf(file, "%d %c", &number, &letter);
    fclose(file);

    // create the array of pointers to structures
    struct Foo **arr = initialize(number);

    // sorting
    sort(number, arr);

    // counting
    int letterCount = count(number, arr, &letter);
    printf("Letter '%c' appears %d times.\n", letter, letterCount);

    // printing the first 20 structures
    for (int i = 0; i < number && i < 20; i++) {
        printf("Structure %d:\nfield int: %d\nfield char: %c\nfield float: %f\n\n", i+1, arr[i]->fieldint, arr[i]->fieldchar, arr[i]->fieldfloat);
    }

    // freeing memory
    deleting(number, arr);

    getch();
    return 0;
}

struct Foo **initialize(int N) {
    struct Foo **array = (struct Foo **)malloc(sizeof(struct Foo *) * N);
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        array[i] = (struct Foo *)malloc(sizeof(struct Foo));
        array[i]->fieldint = rand();
        array[i]->fieldchar = (char)((rand() % 24) + 65);
        array[i]->fieldfloat = (float)i;
    }

    return array;
}

void sort(int N, struct Foo **array) {
    struct Foo *temp;
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j > 0; j--) {
            if (array[j]->fieldint < array[j-1]->fieldint) {
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int count(int N, struct Foo **array, char *X) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (array[i]->fieldchar == *X) {
            counter++;
        }
    }
    return counter;
}

void deleting(int N, struct Foo **array) {
    for (int i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);
}
