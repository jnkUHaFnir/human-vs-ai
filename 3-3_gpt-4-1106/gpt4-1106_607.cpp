#include <iostream>
#include <cstring>

using namespace std;

void swap(char *a, char *b) {
    // Function to swap two strings
    char temp[255];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition(char arr[][255], int left, int right) {
    char pivot[255];
    strcpy(pivot, arr[right]);
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void quicksort(char arr[][255], int left, int right) {
    if (left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

void print(char arr[][255], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int n;
    char ch;

    do {
        cout << "\nEnter Number of Strings: ";
        cin >> n;

        // Create a 2D array (array of strings) with each string having a max length of 254 characters + '\0'
        char arr[n][255];

        cout << "\nEnter Strings to be sorted:\n";
        for (int i = 0; i < n; i++) {
            cout << "Enter string " << i+1 << ": ";
            cin >> arr[i]; // Assuming that strings do not contain spaces. Use cin.getline() for strings with spaces.
        }

        quicksort(arr, 0, n - 1);
        cout << "\nSorted Array:\n";
        print(arr, n);

        cout << "\nWant to sort again? (y/n): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
