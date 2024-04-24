#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Foo {
    int fieldint;
    char fieldchar;
    float fieldfloat;
};

Foo **initialize(int N);
int sort(int N, Foo **array);
int count(int N, Foo **array, char *X);
int deleting(int N, Foo **array);

int main() {
    FILE *file = fopen("inlab01.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        exit(-1);
    }

    int number;
    char letter[1];
    if (fscanf(file, "%d%s", &number, letter) != 2) {
        printf("Invalid input format");
        exit(-1);
    }
    fclose(file);

    Foo **arr = initialize(number);

    sort(number, arr);

    int occurrences = count(number, arr, letter);
    printf("The letter '%c' appeared %d times.\n", *letter, occurrences);

    for (int i = 0; i < number && i < 20; i++) {
        printf("Structure %d:\nfield int:%d\nfield char:%c\nfield float:%f\n\n",
               i + 1, arr[i]->fieldint, arr[i]->fieldchar, arr[i]->fieldfloat);
    }

    deleting(number, arr);

    return 0;
}

Foo **initialize(int N) {
    Foo **array = (Foo **)malloc(sizeof(Foo *) * N);
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        array[i] = (Foo*)malloc(sizeof(Foo));
        array[i]->fieldint = rand();
        array[i]->fieldchar = (char)(rand() % 26) + 'A'; // fix to generate random letter from A to Z
        array[i]->fieldfloat = i;
    }

    return array;
}

int sort(int N, Foo **array) {
    int temp;
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > i; j--) { // change >=j to >i
            if (array[j]->fieldint < array[j - 1]->fieldint) {
                temp = array[j - 1]->fieldint;
                array[j - 1]->fieldint = array[j]->fieldint;
                array[j]->fieldint = temp;
            }
        }
    }
    return 0;
}

int count(int N, Foo **array, char* X) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (array[i]->fieldchar == *X) { // compare with the value pointed to by X
            counter++;
        }
    }
    return counter;
}

int deleting(int N, Foo **array) {
    for (int i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);
    return 0;
}
