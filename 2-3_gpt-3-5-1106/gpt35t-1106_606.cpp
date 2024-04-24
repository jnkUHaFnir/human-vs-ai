#include <iostream>
#include <string.h>

void swap(std::string *a, std::string *b) {   //function to swap elements
    std::string t;
    t = *a;
    *a = *b;
    *b = t;
}

int partition(std::string arr[], int left, int right) {  //function takes last element as pivot and places all smaller elements on left of pivot and greater elements on right
    std::string pivot = arr[right];  //Pivot
    int i = (left - 1);      //index of smaller element

    for (int j = left; j <= (right - 1); j++) {
        if (arr[j] <= pivot) {           //if current element is smaller or equal to pivot, they're swapped
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void quicksort(std::string arr[], int left, int right) { //left is starting index, right is last index
    if (left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);      //sort elements before and after partition
        quicksort(arr, index + 1, right);
    }
}

void print(std::string arr[], int size) {      //function to print elements in array
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int n;      //to store no. of elements in array
    char ch;   //ch for choice
    do {
        std::string *arr = new std::string[n];     //dynamic string array
        std::cout << "Enter Number of Elements:";
        std::cin >> n;
        std::cout << "Enter Elements in Array to be sorted:";

        for (int i = 0; i < n; i++) {
            std::cout << "Enter " << i << "th element:";
            std::cin >> arr[i];
        }

        quicksort(arr, 0, (n - 1));
        
        std::cout << "Sorted Array= ";
        print(arr, n);

        delete[] arr;  // deleting a dynamic array should use [] not just ()
        
        std::cout << "\nWanna sort again? (y/n):";
        std::cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
