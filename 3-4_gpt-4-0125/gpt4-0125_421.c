void sort(struct books *pointer,int n)
{
    int i, j;
    struct books temp; // Temporary storage for swapping
    int sorted; // Flag to check if array is already sorted

    for (i = 0; i < n-1; i++)
    {
        sorted = 1; // Assume the array is sorted
        for (j = 0; j < n-i-1; j++)
        {
            if (strcmp((pointer+j)->name, (pointer+j+1)->name) > 0)
            {
                // Swap records
                temp = *(pointer+j);
                *(pointer+j) = *(pointer+j+1);
                *(pointer+j+1) = temp;

                sorted = 0; // Mark as not sorted
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (sorted) break;
    }
}
