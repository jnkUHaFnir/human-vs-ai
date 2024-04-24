void sort(struct books *pointer, int n)
{
    int i, j, sorted = 0;
    struct books temp;

    for (i = 0; (i < n - 1) && (sorted == 0); i++)
    {
        sorted = 1;
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(pointer[j].name, pointer[j + 1].name) > 0)
            {
                // Swap the books
                temp = pointer[j];
                pointer[j] = pointer[j + 1];
                pointer[j + 1] = temp;

                sorted = 0;
            }
        }
    }
}
