void numberOfTimes(int a[], int b[]) {
    int al = sizeof(a) / sizeof(a[0]);
    int bl = sizeof(b) / sizeof(b[0]);
    int i, p, c;

    for (i = 0; i < al; i++) {
        c = 0;  // Reset the count for each new number in array a
        for (p = 0; p < bl; p++) {
            if (a[i] == b[p]) {
                c++;
            }
        }   
        printf("(%d, %d) ", a[i], c);
    }
}
