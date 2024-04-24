void numberOfTimes(int a[], int b[]) {
    int al = sizeof(a) / sizeof(a[0]);
    int bl = sizeof(b) / sizeof(b[0]);
    int i, p, c = 0;

    for (i = 0; i < al; i++) {  // Use < instead of <=
        for (p = 0; p < bl; p++) {  // Use < instead of <=
            if (a[i] == b[p]) {
                c++;       
            }
        }   
        printf("(%d, %d) ", a[i], c);
        c = 0;  // Reset the count for the next number in array a
    }
}
