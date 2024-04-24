#include <iostream>
#include <string>

using namespace std;

void swap(string &a, string &b)   //function to swap elements, now taking string references
{
    string t = a;
    a = b;
    b = t;
}

int partition(string arr[], int left, int right)  //function to partition taking string array
{
    string pivot = arr[right];  //Pivot now is a string
    int i = (left - 1);

    for(int j = left; j <= (right - 1); j++)
    {
        if(arr[j] <= pivot) //Comparing strings
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void quicksort(string arr[], int left, int right) //function to perform quick sort on string array
{
    if(left < right)
    {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);  //sort elements before and after partition
        quicksort(arr, index + 1, right);
    }
}

void print(string *arr, int size)   //function to print elements in array, now taking string array
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;      //to store no. of elements in array
    char ch;   //ch for choice
    do{
        cout << "\nEnter Number of Elements:";
        cin >> n;
        
        string* arr = new string[n];   //dynamic string array
        
        cout << "\nEnter Elements in Array to be sorted:";
        for(int i = 0; i < n; i++)
        {
            cout << "\nEnter " << i+1 << "th element: ";
            cin >> arr[i];
        }
        quicksort(arr, 0, (n - 1));
        cout << "\nSorted Array= ";
        print(arr, n);
        delete[] arr; // Properly deleting the dynamically allocated array
        cout << "\nWanna sort again??(y/n):";
        cin >> ch;
    }while(ch == 'Y' || ch == 'y');
    return 0;
}
