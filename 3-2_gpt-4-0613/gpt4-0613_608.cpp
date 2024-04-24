#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void swap(string* a, string* b)
{
    string t;
    t = *a;
    *a = *b;
    *b = t;
}

int partition(string arr[], int low, int high)
{
    string pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(string arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void print(string arr[], int length)
{
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    char ch;

    do {
        cout << "\nEnter number of elements: ";
        cin >> n;

        string* arr = new string[n];

        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter element " << i + 1 << ": ";
            cin >> arr[i];
        }

        quickSort(arr, 0, n - 1);

        cout << "\nSorted Array = ";
        print(arr, n);

        delete[] arr;
        
        cout << "\nWanna sort again? (y/n): ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');

    return 0;
}
