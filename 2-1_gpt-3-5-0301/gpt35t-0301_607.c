#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LENGTH = 100;

void swap(char *a, char *b) {
    char t[MAX_LENGTH];
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
}

int partition(char arr[][MAX_LENGTH], int left, int right) {
    char *pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i+1;
}

void quicksort(char arr[][MAX_LENGTH], int left, int right) {
    if (left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

void print(char arr[][MAX_LENGTH], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    char ch;
    do {
        char arr[MAX_LENGTH][MAX_LENGTH];
        cout << "Enter Number of Strings: ";
        cin >> n;
        cout << "Enter Strings to be sorted: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        quicksort(arr, 0, n - 1);
        cout << "Sorted Strings: ";
        print(arr, n);
        cout << "\nWanna Sort Again? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
