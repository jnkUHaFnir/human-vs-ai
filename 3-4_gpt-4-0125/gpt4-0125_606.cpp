#include<iostream>
#include<cstring>

using namespace std;

void swap(char **a, char **b) { // Function to swap elements (pointers to char)
    char *t = *a;
    *a = *b;
    *b = t;
}

int partition(char *arr[], int left, int right) {
    char *pivot = arr[right]; // Pivot is now a char pointer
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (strcmp(arr[j], pivot) <= 0) { // Use strcmp for comparison
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void quicksort(char *arr[], int left, int right) { // Modify parameter type to char*
    if (left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

void print(char *arr[], int size) { // Function to print elements of string array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n; // To store number of elements (strings) in array
    char ch; // ch for choice

    do{
        clrscr();
        cout << "\nEnter Number of Elements: ";
        cin >> n;
        cin.ignore(); // Ignore the newline character left in the buffer

        char **arr = new char*[n]; // Dynamic array of char pointers (strings)

        for (int i = 0; i < n; i++) {
            arr[i] = new char[101]; // Assume max length of string is 100
            cout << "Enter " << i << "th element: ";
            cin.getline(arr[i], 101); // Read strings including spaces
        }

        quicksort(arr, 0, n - 1);

        cout << "\nSorted Array= ";
        print(arr, n);

        // Free dynamically allocated memory
        for(int i = 0; i < n; i++) {
            delete[] arr[i];
        }
        delete[] arr;

        cout << "wanna sort again??(y/n): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
