#include <iostream>
#include <cstring>

using namespace std;

void swap(char* a, char* b)   // function to swap elements
{
    char* t = a;
    a = b;
    b = t;
}

int partition(char** arr, int left, int right)  // function takes last element as pivot and places all smaller elements on left of pivot and greater elements on right
{
    char* pivot = arr[right];  // Pivot
    int i = (left - 1);      // index of smaller element

    for (int j = left; j <= (right - 1); j++)
    {
        if (strcmp(arr[j], pivot) <= 0)           // if current element is smaller or equal to pivot, they're swapped
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void quicksort(char** arr, int left, int right) // left is starting index, right is last index
{
    if (left < right)
    {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);      // sort elements before and after partition
        quicksort(arr, index + 1, right);
    }
}

void print(char** arr, int size)      // function to print elements in array
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    size_t n;      // to store no. of elements in array
    char ch;   // ch for choice
    do {
        char** arr = NULL;     // dynamic string array
        cout << "\nEnter Number of Elements: ";
        cin >> n;
        arr = new char* [n];
        cout << "\nEnter Elements in Array to be sorted: ";
        for (size_t i = 0; i < n; i++)
        {
            arr[i] = new char[100];  // assuming string length limit of 100 characters
            cout << "\nEnter " << i + 1 << "th element: ";
            scanf("%s", arr[i]);
        }
        quicksort(arr, 0, (n - 1));
        cout << "\nSorted Array= ";
        print(arr, n);
        for (size_t i = 0; i < n; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        cout << "\nwanna sort again??(y/n): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    return 0;
}
