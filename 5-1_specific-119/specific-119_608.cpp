#include <iostream>
#include <cstring>
using namespace std;

void swap(char *a, char *b) {
    char *t = new char[strlen(a) + 1];
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
    delete[] t;
}

int partition(char* arr[], int left, int right) {
    char* pivot = arr[right];
    int i = left - 1;

    for(int j = left; j < right; j++) {
        if(strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quicksort(char* arr[], int left, int right) {
    if(left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

void print(char* arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    char ch;
    do {
        char **arr = NULL;
        cout << "Enter Number of Strings: ";
        cin >> n;

        arr = new char*[n];
        cout << "Enter " << n << " strings to be sorted: " << endl;
        for (int i = 0; i < n; i++) {
            arr[i] = new char[100]; // Assuming maximum string length is 99
            cin >> arr[i];
        }

        quicksort(arr, 0, n - 1);

        cout << "Sorted Strings: ";
        print(arr, n);

        for (int i = 0; i < n; i++) {
            delete[] arr[i];
        }
        delete[] arr;

        cout << "Do you want to sort again? (y/n): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
