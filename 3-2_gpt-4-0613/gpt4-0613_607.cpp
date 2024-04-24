// New: Include library for strcmp
#include<cstring>

void swap(char** a, char** b)   //function to swap elements
{
    char* t;
     t = *a;
    *a = *b;
    *b = t;
}

int partition(char* arr[], int left, int right)  //function takes last element as pivot and places all smaller elements on left of pivot and greater elements on right
{
    char* pivot=arr[right];  //Pivot
    int i= (left-1);      //index of smaller element

    for(int j=left; j<=(right-1); j++)
    {
        // New: comparison depends on strcmp
        if(strcmp(arr[j], pivot) <= 0)           //if current element is smaller or equal to pivot, theyre swapped
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[right]);
    return (i+1);
}

void quicksort(char* arr[], int left, int right) //left is starting index, right is last index
{
    if(left<right)
    {
        int index=partition(arr,left,right);
        quicksort(arr, left, index-1);      //sort elements before and after partition
        quicksort(arr, index+1, right);
    }
}

void print(char** arr, int size)      //function to print elements in array
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
        char **arr = NULL;     //dynamic char** array
        clrscr();
    cout<<"\nEnter Number of Elements:";
    cin>>n;
    cout<<"\nEnter Elements in Array to be sorted:";
    // New: allocate entire array at the same time
    arr = new char*[n];
    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter "<<i<<"th element:";
        // New: allocation of each char array and input
        arr[i] = new char[20]; // assuming max length of 19 characters + null terminator
        cin>>arr[i];
    }
    quicksort(arr,0,(n-1));
    cout<<"\nSorted Array= ";
    print(arr,n);

    // New: need to delete individual char arrays
    for(int i=0; i<n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    cout<<"\nwanna sort again??(y/n):";
    cin>>ch;
    }while(ch=='Y'||ch=='y');
    return 0;
}
