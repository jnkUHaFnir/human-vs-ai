#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Foo {
    int fieldint;
    char fieldchar;
    float fieldfloat;
};

struct Foo **initialize(int N);
void sort(int N, struct Foo **tablica);
int count(int N, struct Foo **tablica, char *X);
void deleting(int N, struct Foo **tablica);

int main() {

    FILE *file = fopen("inlab01.txt", "r");
    int number;
    char letter;
    if (file == NULL) {
        printf("Error opening file");
        exit(-1);
    }
    fscanf(file, "%d %c", &number, &letter);
    fclose(file);

    struct Foo **arr = initialize(number);

    sort(number, arr);
    int letterCount = count(number, arr, &letter);

    for (int i = 0; i < number && i < 20; i++) {
        printf("Structure %d:\nfield int: %d\nfield char: %c\nfield float: %f\n\n", i + 1, arr[i]->fieldint, arr[i]->fieldchar, arr[i]->fieldfloat);
    }

    deleting(number, arr);

    return 0;
}

struct Foo **initialize(int N) {
    struct Foo **array = (struct Foo **)malloc(sizeof(struct Foo) * N);
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        array[i] = (struct Foo *)malloc(sizeof(struct Foo));
        array[i]->fieldint = rand();
        array[i]->fieldchar = (char)(rand() % 24) + 65;
        array[i]->fieldfloat = i;
    }

    return array;
}

void sort(int N, struct Foo **array) {
    struct Foo *temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (array[j]->fieldint > array[j + 1]->fieldint) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
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
