#include<iostream>
#include<string>
#include<vector>

using namespace std;

void swap(string &a, string &b)   //function to swap strings
{
    string t = a;
    a = b;
    b = t;
}

int partition(vector<string> &arr, int left, int right)  //function that takes last element as pivot
{
    string pivot = arr[right];  //Pivot
    int i = (left - 1);      //index of smaller element

    for(int j = left; j <= (right - 1); j++)
    {
        if(arr[j] <= pivot)           //if current string is smaller or equal to pivot, they are swapped
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void quicksort(vector<string> &arr, int left, int right) //left is starting index, right is last index
{
    if(left < right)
    {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1);      //sort elements before and after partition
        quicksort(arr, index + 1, right);
    }
}

void print(vector<string> &arr, int size)      //function to print elements in array
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;      //to store the number of strings in array
    char ch;   //ch for choice
    do{
        vector<string> arr;     //dynamic string vector
        cout << "\nEnter Number of Strings:";
        cin >> n;
        cout << "\nEnter Strings in Array to be sorted:";
        for(int i = 0; i < n; i++)
        {
            string s;
            cout << "\nEnter " << i << "th string:";
            cin >> s;
            arr.push_back(s);
        }
        quicksort(arr, 0, (n - 1));
        cout << "\nSorted Array= ";
        print(arr, n);
        cout << "\nwanna sort again??(y/n):";
        cin >> ch;
    } while(ch == 'Y' || ch == 'y');
    return 0;
}
