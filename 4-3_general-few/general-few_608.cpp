#include <iostream>
#include <conio.h>
#include <cstring>

void swap(char *a, char *b) {
    char* temp = new char[strlen(a) + 1];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
    delete[] temp;
}

int partition(char* arr[], int left, int right) {
    char* pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void quicksort(char* arr[], int left, int right) {
    if (left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

void print(char* arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int n;
    char ch;
    do {
        char** arr = nullptr;
        clrscr();
        std::cout << "\nEnter Number of Strings: ";
        std::cin >> n;

        arr = new char*[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new char[100]; // Assuming max length of string is 100
            std::cout << "\nEnter " << i << "th string: ";
            std::cin >> arr[i];
        }

        quicksort(arr, 0, n - 1);

        std::cout << "\nSorted Strings:";
        print(arr, n);

        for (int i = 0; i < n; i++) {
            delete[] arr[i];
        }
        delete[] arr;

        std::cout << "\nSort again? (y/n): ";
        std::cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
