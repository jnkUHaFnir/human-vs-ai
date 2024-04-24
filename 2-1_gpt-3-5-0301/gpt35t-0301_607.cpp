#include<iostream>
#include<string>
using namespace std;

void swap(string *a, string *b)   //function to swap elements
{
    string t = *a;
    *a = *b;
    *b = t;
}

int partition(string arr[], int left, int right)  //function takes last element as pivot and places all smaller elements on left of pivot and greater elements on right
{
    string pivot = arr[right];  //Pivot
    int i = (left-1);      //index of smaller element

    for(int j=left; j<=(right-1); j++)
    {
        if(arr[j]<=pivot)           //if current element is smaller or equal to pivot, they're swapped
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[right]);
    return (i+1);
}

void quicksort(string arr[], int left, int right) //left is starting index, right is last index
{
    if(left<right)
    {
        int index=partition(arr,left,right);
        quicksort(arr, left, index-1);      //sort elements before and after partition
        quicksort(arr, index+1, right);
    }
}

void print(string *arr, int size)      //function to print elements in array
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;      //to store no. of elements in array
    char ch;   //ch for choice
    do{
        string *arr=NULL;     //dynamic string array
        cout<<"\nEnter Number of Elements:";
        cin>>n;
        arr = new string[n];    //allocate memory for string array
        cout<<"\nEnter Elements in Array to be sorted:";
        for(int i=0; i<n; i++)
        {
            cout<<"\nEnter "<<i+1<<"th element:";
            cin>>arr[i];
        }
        quicksort(arr,0,(n-1));
        cout<<"\nSorted Array= ";
        print(arr,n);
        delete [] arr;   //deallocate memory for string array
        cout<<"\nwanna sort again??(y/n):";
        cin>>ch;
    }while(ch=='Y'||ch=='y');
    return 0;
}