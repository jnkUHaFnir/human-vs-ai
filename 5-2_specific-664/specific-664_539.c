for (i = 0; i <= al; i++) {
    for (p = 0; i <= bl; p++) { // <---- This line has a mistake
        if (a[i] == b[p]) {
            c++;       
        }
    }   
    printf("(%d, %d) ", a[i], c);
}
void numberOfTimes(int a[], int b[]) {
    int al = sizeof(a) / sizeof(a[0]);
    int bl = sizeof(b) / sizeof(b[0]);
    int i, p, c;

    for (i = 0; i < al; i++) {
        c = 0;
        for (p = 0; p < bl; p++) {
            if (a[i] == b[p]) {
                c++;
            }
        }   
        printf("(%d, %d) ", a[i], c);
    }
}
