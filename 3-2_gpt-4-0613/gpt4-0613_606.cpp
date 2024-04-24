void swap(string* a, string* b) 
{
    string temp = *a;
    *a = *b;
    *b = temp;
}
int partition(string arr[], int left, int right)
{
    string pivot = arr[right]; //pivot
    int i = (left - 1); //index of smaller element
    for (int j = left; j <= right - 1; j++)
    {
        if (arr[j] <= pivot) 
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}
void quicksort(string arr[], int left, int right) {...}
void print(string* arr, int size) {...}
string* arr = new string[n];
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void swap(string *a, string *b) 
{
    string t = *a;
   *a = *b;
   *b = t;
}

int partition(string arr[], int left, int right) 
{
    string pivot = arr[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++)
    {
        if (arr[j] <= pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void quicksort(string arr[], int left, int right) 
{
    if (left < right) 
    {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);  
        quicksort(arr,index + 1, right);
    }
}

void print(string* arr, int size) 
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int n;
    char ch;
    do {
        clrscr();
        cout << "\nEnter number of elements:";
        cin >> n;
        string* arr = new string[n];
        cout << "\nEnter elements in array to be sorted:";
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter " << i << "th element:";
            cin >> arr[i];
        }
        quicksort(arr, 0, n - 1);
        cout << "\nSorted Array= ";
        print(arr, n);
        delete[] arr;
        cout << "\nWant to sort again?? (y/n):";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    
    return 0;
}
