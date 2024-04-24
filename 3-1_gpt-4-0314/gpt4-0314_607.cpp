#include<iostream>
#include<cstring>
#include<cstddef>

void swap_string(char **a, char **b) //function to swap strings
{
    char *t = *a;
    *a = *b;
    *b = t;
}

int partition(char **arr, int left, int right) //function takes last string as pivot and places all smaller strings on left of pivot and greater strings on right
{
    char *pivot = arr[right]; //Pivot
    int i = (left - 1); //index of smaller string

    for (int j = left; j <= (right - 1); j++)
    {
        if (strcmp(arr[j], pivot) <= 0) //if current string is smaller or equal to pivot, they're swapped
        {
            i++;
            swap_string(&arr[i], &arr[j]);
        }
    }
    swap_string(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void quicksort(char **arr, int left, int right) //left is starting index, right is last index
{
    if (left < right)
    {
        int index = partition(arr, left, right);
        quicksort(arr, left, index - 1); //sort strings before and after partition
        quicksort(arr, index + 1, right);
    }
}

void print(char **arr, int size) //function to print elements in array
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}

int main()
{
    int n; //to store number of strings in array
    char ch; //ch for choice
    do
    {
        std::cout << "\nEnter Number of Strings:";
        std::cin >> n;

        char **arr = new char *[n]; //dynamic char array

        for (int i = 0; i < n; i++)
        {
            arr[i] = new char[256]; //allocate memory for each string (assuming max string length = 255 + null terminator)
        }

        std::cout << "\nEnter Strings in Array to be sorted:";
        for (int i = 0; i < n; i++)
        {
            std::cout << "\nEnter " << i << "th string:";
            std::cin >> arr[i];
        }
        quicksort(arr, 0, (n - 1));
        std::cout << "\nSorted Array = ";
        print(arr, n);

        //deallocate memory
        for (int i = 0; i < n; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;

        std::cout << "\nwanna sort again??(y/n):";
        std::cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    return 0;
}
