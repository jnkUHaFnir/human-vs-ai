#include<iostream>
#include<cstring>  // For strcmp and strcpy

using namespace std;

void swap(char **a, char **b) { // Function to swap string pointers
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char* arr[], int left, int right) { // Partition function for strings
    char* pivot = arr[right];

    int i = (left - 1);
    for(int j = left; j <= (right - 1); j++) {
        if(strcmp(arr[j], pivot) <= 0) { // Comparing strings
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[right]);
    return (i+1);
}

void quicksort(char* arr[], int left, int right) { // Quicksort for strings
    if(left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

void print(char* arr[], int size) { // Function to print array of strings
    for(int i = 0; i < size; i++) {
        cout << arr[i] << "\n";
    }
}

int main() {
    int n; // Number of strings
    char ch; // Variable to hold choice for re-sorting

    do {
        cout << "\nEnter Number of Strings: ";
        cin >> n;
        cin.ignore(); // Clearing buffer before reading strings
        
        char** arr = new char*[n]; // Dynamic array of char pointers
        for(int i = 0; i < n; i++) {
            arr[i] = new char[100]; // Assuming each string can have up to 99 characters plus null terminator
            cout << "Enter " << i << "th string: ";
            cin.getline(arr[i], 100); // Reading string
        }
        
        quicksort(arr, 0, n-1);
        
        cout << "\nSorted Array of Strings: \n";
        print(arr, n);
        
        // Cleaning up dynamic memory
        for(int i = 0; i < n; i++) {
            delete[] arr[i];
        }
        delete[] arr;
        
        cout << "\nWanna sort again? (y/n): ";
        cin >> ch;
        cin.ignore(); // Clearing buffer after reading char
    } while(ch == 'Y' || ch == 'y');

    return 0;
}
