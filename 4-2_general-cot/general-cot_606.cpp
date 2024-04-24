#include <iostream>
#include <string>
#include <algorithm>

void swap(std::string& a, std::string& b) {
    std::string t = a;
    a = b;
    b = t;
}

int partition(std::string arr[], int left, int right) {
    std::string pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void quicksort(std::string arr[], int left, int right) {
    if (left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

void print(std::string arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int n;
    char ch;
    do {
        std::string* arr = new std::string[n]; // dynamic string array

        std::cout << "\nEnter Number of Strings:";
        std::cin >> n;
        
        std::cout << "\nEnter Strings to be sorted:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << "Enter " << i << "th string: ";
            std::cin >> arr[i];
        }

        quicksort(arr, 0, n - 1);

        std::cout << "\nSorted Strings: ";
        print(arr, n);

        delete[] arr;

        std::cout << "\nSort again? (y/n): ";
        std::cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    
    return 0;
}
