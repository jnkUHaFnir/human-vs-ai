#include <iostream>
#include <cstring>

void swap(char* a, char* b) {
    char t[100];
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
}

int partition(char arr[][100], int left, int right) {
    char pivot[100];
    strcpy(pivot, arr[right]);
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

void quicksort(char arr[][100], int left, int right) {
    if (left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

void print(char arr[][100], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int n;
    char ch;
    do {
        char arr[100][100];
        std::cout << "\nEnter Number of Strings: ";
        std::cin >> n;
        std::cout << "\nEnter Strings to be sorted: ";
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        quicksort(arr, 0, n - 1);
        std::cout << "\nSorted Strings: ";
        print(arr, n);
        std::cout << "\nWanna sort again? (y/n): ";
        std::cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
