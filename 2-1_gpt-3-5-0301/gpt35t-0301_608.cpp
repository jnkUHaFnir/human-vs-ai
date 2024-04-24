
int partition(char arr[][100], int left, int right)  //function takes last element as pivot and places all smaller elements on left of pivot and greater elements on right
{
    char pivot[100];
    strcpy(pivot, arr[right]);  //Pivot
    int i= (left-1);      //index of smaller element

    for(int j=left; j<=(right-1); j++)
    {
        if(strcmp(arr[j], pivot)<=0)           //if current element is smaller or equal to pivot, they're swapped
        {
            i++;
            swap(arr[i], arr[j]);    //use char array swapping function instead of integer swapping function
        }
    }
    swap(arr[i+1], arr[right]);     //use char array swapping function instead of integer swapping function
    return (i+1);
}