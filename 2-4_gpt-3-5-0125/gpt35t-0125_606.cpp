#include<iostream>
#include<cstring>
using namespace std;

void swap(char *a, char *b) {
    char* t = new char[strlen(a) + 1];
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
    delete[] t;
}

int partition(char** arr, int left, int right) {
    char* pivot = arr[right];
    int i = left - 1;

    for(int j = left; j <= right - 1; j++) {
        if(strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void quicksort(char** arr, int left, int right) {
    if(left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

void print(char** arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    char ch;
    do {
        char** arr = new char*[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new char[100]; // assuming max string length is 100
            cout << "Enter " << i << "th element:";
            cin.getline(arr[i], 100);
        }

        cout << "Enter Number of Strings:";
        cin >> n;

        quicksort(arr, 0, n - 1);

        cout << "\nSorted Array= ";
        print(arr, n);

        for (int i = 0; i < n; i++) {
            delete[] arr[i];
        }
        delete[] arr;

        cout << "\nDo you want to sort again? (y/n):";
        cin >> ch;
        cin.ignore(); // to clear the input buffer
    } while(ch == 'Y' || ch == 'y');

    return 0;
}
