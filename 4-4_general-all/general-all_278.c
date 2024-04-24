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
    int number;
    char letter[2]; // Make space for the null terminator
    if (file == NULL) {
        printf("Error opening file");
        exit(-1);
    } 
    fscanf(file, "%d%s", &number, letter);
    fclose(file);

    Foo **arr = initialize(number);
    
    sort(number, arr);

    //count(number, arr, letter);

    for (int i = 0; i < 20; i++) {
        printf("Structure %d:\nfield int: %d\nfield char: %c\nfield float: %f\n\n", i+1, arr[i]->fieldint, arr[i]->fieldchar, arr[i]->fieldfloat);
    }

    deleting(number, arr);

    return 0;
}

Foo **initialize(int N) {
    Foo **array = (Foo **)malloc(sizeof(Foo *) * N);
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        array[i] = (Foo *)malloc(sizeof(Foo));
        array[i]->fieldint = rand();  
        array[i]->fieldchar = (char)(rand() % 24) + 65;
        array[i]->fieldfloat = (float)i;
    }

    return array;
}

int sort(int N, Foo **array) {
    int temp;
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > 0; j--) {
            if (array[j]->fieldint < array[j - 1]->fieldint) {
                temp = array[j - 1]->fieldint;
                array[j - 1]->fieldint = array[j]->fieldint;
                array[j]->fieldint = temp;
            }
        }
    }
    return 0;
}

int count(int N, Foo **array, char *X) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (array[i]->fieldchar == *X) {
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
