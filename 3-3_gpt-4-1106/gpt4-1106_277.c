#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

struct Foo {
    int fieldint;
    char fieldchar;
    float fieldfloat;
};

struct Foo **initialize(int N);
void sort(int N, struct Foo **tablica);
int count(int N, struct Foo **tablica, char X);
void deleting(int N, struct Foo **tablica);

int main() {
    // ... the same as before ...

    // Creating the array
    struct Foo **arr = initialize(number);

    // Sorting:
    sort(number, arr);

    // Counting how many times the given letter appears:
    int letter_count = count(number, arr, letter[0]);
    printf("The letter '%c' appears %d times.\n", letter[0], letter_count);

    // Printing the first 20 of the structures
    for(int i = 0; i < 20 && i < number; i++) {
        printf("Structure %d:\nfield int: %d\nfield char: %c\nfield float: %f\n\n",
               i+1, arr[i]->fieldint, arr[i]->fieldchar, arr[i]->fieldfloat);
    }

    // Deleting:
    deleting(number, arr);

    getch();
    return 0;
}

struct Foo **initialize(int N) {
    struct Foo **array = (struct Foo **)malloc(sizeof(struct Foo *) * N);
    srand(time(NULL));    

    for(int i = 0; i < N; i++) {
        array[i] = (struct Foo *)malloc(sizeof(struct Foo));           
        array[i]->fieldint = rand();  // Random number
        array[i]->fieldchar = (char)(rand() % 26) + 65; // Random letter A-Z
        array[i]->fieldfloat = (float)i;     
    }

    return array; 
}

void sort(int N, struct Foo **array) {
    struct Foo *temp;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (array[j]->fieldint < array[i]->fieldint) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
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

void deleting(int N, struct Foo **array) {
    for (int i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);
}
