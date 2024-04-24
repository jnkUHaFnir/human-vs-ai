void sort(struct books *pointer, int n) {
    int i, j, sorted;
    struct books temp;

    for(i = 0; i < n - 1; i++) {
        sorted = 1; // initialize sorted flag

        for(j = 0; j < n - i - 1; j++) {
            if(strcmp((pointer + j)->name, (pointer + j + 1)->name) > 0) {
                // swap the elements
                temp = *(pointer + j);
                *(pointer + j) = *(pointer + j + 1);
                *(pointer + j + 1) = temp;
                sorted = 0; // update sorted flag
            }
        }

        if (sorted == 1) {
            // If no swaps are done in a pass, the array is already sorted
            break;
        }
    }
}
