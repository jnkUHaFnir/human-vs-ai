void swap(char *a, char *b) {
    char t[100];  // Assuming a maximum string length of 100 characters
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
}
int partition(char arr[][100], int left, int right) {
    char pivot[100];
    strcpy(pivot, arr[right]);
    int i = (left - 1);

    for (int j = left; j <= (right - 1); j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}
void print(char arr[][100], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
int main() {
    int n;
    char ch;
    do {
        char arr[100][100];  // Assuming array of strings with each string not exceeding 100 characters

        clrscr();
    
        cout << "\nEnter Number of Strings:";
        cin >> n;
    
        cout << "\nEnter Strings to be sorted:\n";
        cin.ignore();  // To consume the newline character left in the buffer
    
        for (int i = 0; i < n; i++) {
            cout << "Enter string " << i + 1 << ": ";
            cin.getline(arr[i], 100);  // Read strings with spaces
        }
    
        quicksort(arr, 0, n-1);
    
        cout << "\nSorted Array:\n";
        print(arr, n);
    
        cout << "\nWanna sort again??(y/n): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    
    return 0;
}
