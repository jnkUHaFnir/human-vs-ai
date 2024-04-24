#include <iostream>
#include <cstring> // for strcmp and strcpy
#include <cstdlib> // for dynamic memory allocation

using namespace std;

const int MAX_LENGTH = 256; // Maximum length for each string
const int MAX_STRINGS = 100; // Maximum number of strings

void swap(char** a, char** b) {  // Function to swap elements
    char* t = *a;
    *a = *b;
    *b = t;
}

int partition(char* arr[], int left, int right) {
    char* pivot = arr[right];  // Pivot
    int i = (left - 1);       // Index of smaller element

    for (int j = left; j <= (right - 1); j++) {
        if (strcmp(arr[j], pivot) <= 0) {  // If current element is smaller or equal to pivot, they're swapped
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void quicksort(char* arr[], int left, int right) {
    if (left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);      // Sort elements before and after partition
        quicksort(arr, index + 1, right);
    }
}

void print(char* arr[], int size) { // Function to print elements in the array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\n";
    }
    cout << endl;
}

int main() {
    int n;           // To store the number of strings
    char ch;         // To store the user choice
    char* arr[MAX_STRINGS];   // Array of strings (change if you're using dynamic allocation)

    do {
        cout << "\nEnter Number of Strings (max " << MAX_STRINGS << "): ";
        cin >> n;

        // Allocate memory for each string
        for (int i = 0; i < n; i++) {
            arr[i] = new char[MAX_LENGTH];
        }

        cout << "\nEnter Strings to be sorted:\n";
        cin.ignore();  // To consume the newline character from the previous input
        for (int i = 0; i < n; i++) {
            cout << "Enter string " << i + 1 << ": ";
            cin.getline(arr[i], MAX_LENGTH);
        }

        quicksort(arr, 0, n - 1);
        cout << "\nSorted Array:\n";
        print(arr, n);

        // Free the allocated memory for each string
        for (int i = 0; i < n; i++) {
            delete[] arr[i];
        }

        cout << "Wanna sort again? (y/n): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
