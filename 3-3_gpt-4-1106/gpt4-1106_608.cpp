#include <iostream>
#include <cstring> // For strcmp and strcpy

using namespace std;

void swap(char* a, char* b) {
    char temp[256];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition(char arr[][256], int left, int right) {
    char* pivot = arr[right];
    int i = (left - 1);

    for (int j = left; j <= (right - 1); j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return (i + 1);
}

void quicksort(char arr[][256], int left, int right) {
    if (left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

void print(char arr[][256], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int n;
    char ch;
    do {
        char arr[100][256]; // Modify size as needed, here we consider maximum 100 strings with each up to 255 characters plus null terminator

        cout << "\nEnter Number of Strings: ";
        cin >> n;

        if(n > 100) { // Preventing buffer overflow
            cout << "Maximum number of strings (100) exceeded." << endl;
            continue;
        }

        cout << "\nEnter Strings to be sorted:\n";
        for(int i = 0; i < n; i++) {
            cout << "Enter string " << i << ": ";
            cin >> arr[i]; // Read each string
        }

        quicksort(arr, 0, (n - 1));
        cout << "\nSorted Array:\n";
        print(arr, n);

        cout << "\nWanna sort again? (y/n): ";
        cin >> ch;
    } while(ch == 'Y' || ch == 'y');
    
    return 0;
}
