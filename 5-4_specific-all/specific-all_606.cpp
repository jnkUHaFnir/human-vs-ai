#include<iostream>
#include<string>
#include<algorithm>

void swap(char **a, char **b) {
    char *t = *a;
    *a = *b;
    *b = t;
}

int partition(char **arr, int left, int right) {
    char *pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void quicksort(char **arr, int left, int right) {
    if (left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

void print(char **arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int size;
    char choice;
    do {
        char **arr = nullptr;

        std::cout << "\nEnter Number of Strings:";
        std::cin >> size;

        arr = new char *[size];
        for (int i = 0; i < size; i++) {
            arr[i] = new char[100]; // Assuming max string length is 100
            std::cout << "Enter " << i + 1 << "th string: ";
            std::cin >> arr[i];
        }

        quicksort(arr, 0, size - 1);

        std::cout << "\nSorted Strings: ";
        print(arr, size);

        for (int i = 0; i < size; i++) {
            delete[] arr[i];
        }
        delete[] arr;

        std::cout << "\nSort again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
