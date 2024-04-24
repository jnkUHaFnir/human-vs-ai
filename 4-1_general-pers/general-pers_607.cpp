#include <iostream>
#include <cstring>

void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char** arr, int left, int right) {
    char* pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void quicksort(char** arr, int left, int right) {
    if (left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

void print(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    char ch;

    do {
        char** arr = nullptr;
        std::cout << "Enter Number of Strings:";
        std::cin >> n;

        arr = new char*[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new char[100]; // assuming max length of each string is 100 characters
            std::cout << "Enter " << i << "th string:";
            std::cin >> arr[i];
        }

        quicksort(arr, 0, n - 1);

        std::cout << "Sorted Strings: ";
        print(arr, n);

        for (int i = 0; i < n; i++) {
            delete[] arr[i];
        }
        delete[] arr;

        std::cout << "Want to sort again? (y/n):";
        std::cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
