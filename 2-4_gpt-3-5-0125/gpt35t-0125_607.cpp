#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void swap(string *a, string *b) {
    string t = *a;
    *a = *b;
    *b = t;
}

int partition(string arr[], int left, int right) {
    string pivot = arr[right];
    int i = (left-1);

    for(int j=left; j<=(right-1); j++) {
        if(arr[j]<=pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[right]);
    return (i+1);
}

void quicksort(string arr[], int left, int right) {
    if(left<right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index-1);
        quicksort(arr, index+1, right);
    }
}

void print(string arr[], int size) {
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    char ch;
    do{
        string *arr = new string[n];
        cout << "\nEnter Number of Strings: ";
        cin >> n;
        
        cout << "\nEnter Strings to be sorted:";
        for(int i=0; i<n; i++) {
            cout << "\nEnter " << i << "th string: ";
            cin >> arr[i];
        }
        
        quicksort(arr, 0, n-1);
        
        cout << "\nSorted Strings: ";
        print(arr, n);
        
        delete[] arr;
        
        cout << "\nWant to sort again? (Y/N): ";
        cin >> ch;
    } while(ch=='Y' || ch=='y');
    
    return 0;
}
