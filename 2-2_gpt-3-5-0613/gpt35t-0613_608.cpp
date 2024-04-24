#include<iostream>
#include<string.h>
using namespace std;

void swap(char **a, char **b) {
    char *t = *a;
    *a = *b;
    *b = t;
}

int partition(char **arr, int left, int right) {
    char *pivot = arr[right];
    int i = left - 1;

    for(int j = left; j <= right - 1; j++) {
        if(strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void quicksort(char **arr, int left, int right) {
    if(left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

void print(char **arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    char ch;
    do {
        char **arr = NULL;
        cout << "\nEnter Number of Strings:";
        cin >> n;

        arr = new char *[n];

        cout << "\nEnter Strings to be sorted:";
        for(int i = 0; i < n; i++) {
            arr[i] = new char[100]; // assuming max string length is 100
            cout << "\nEnter " << i << "th string:";
            cin >> arr[i];
        }

        quicksort(arr, 0, n - 1);

        cout << "\nSorted Array= ";
        print(arr, n);

        for(int i = 0; i < n; i++) {
            delete[] arr[i];
        }
        delete[] arr;

        cout << "\nwanna sort again??(y/n):";
        cin >> ch;
    } while(ch == 'Y' || ch == 'y');

    return 0;
}
