#include <iostream>
#include <string>
#include <algorithm>

void swap(char* &a, char* &b) {
    char* temp = a;
    a = b;
    b = temp;
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
    return i + 1;
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
    char choice;

    do {
        char** arr = nullptr;
        std::cout << "\nEnter Number of Elements: ";
        std::cin >> n;

        arr = new char*[n];
        
        std::cout << "\nEnter Elements in Array to be sorted:\n";
        for (int i = 0; i < n; i++) {
            arr[i] = new char[100]; // Assuming max input size of each string is 100 characters
            std::cout << "Enter " << i << "th element: ";
            std::cin >> arr[i];
        }

        quicksort(arr, 0, n - 1);

        std::cout << "\nSorted Array = ";
        print(arr, n);

        for (int i = 0; i < n; i++) {
            delete[] arr[i];
        }
        delete[] arr;

        std::cout << "\nWanna sort again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
