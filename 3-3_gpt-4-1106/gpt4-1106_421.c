void sort(struct books *pointer, int n) {
    int i, j, sorted;
    struct books temp;
    for (i = 0; i < n - 1; i++) { // You do not need 'sorted' as you will be checking all combinations
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(pointer[j].name, pointer[j + 1].name) > 0) {
                // Swap the records by copying entire struct at once
                temp = pointer[j];
                pointer[j] = pointer[j + 1];
                pointer[j + 1] = temp;
            }
        }
    }
}
int main() {
    // ... (rest of your code remains the same)

    // Add this before closing the main function
    return 0;
}
