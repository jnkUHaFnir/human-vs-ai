    #include <stdio.h>
    void sort(int a[], int l) {
        int i, j, t; 
        for (i = 0; i < l; i++) {
            for (j = 0; j < l - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    t = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = t;
                }
            }
        }
    }
    void numberOfTimes(int a[], int al, int b[], int bl) {
        int i, p, c;
	
        for (i = 0; i < al; i++) {
            c = 0;
            for (p = 0; i < bl; p++) {
                if (a[i] == b[p]) {
                    c++;       // <-------- This line doesn't work. Why?
                }
            }	
            printf("(%d, %d) ", a[i], c);
        }
    }
    int main(void) {
        int maxarraylen = 1000, i;
        int a[maxarraylen];
        int b[maxarraylen];
        int al, bl, v, t;
	
        printf("Type elements of A separated by spaces. Do not enter duplicates (type 'end' to stop): ");
        while (scanf("%d", &a[i]) == 1)
            i++;
        scanf("%*s");
        al = i;
        i = 0;
	
        printf("Type elements of B separated by spaces(type 'end' to stop): ");
        while (scanf("%d", &b[i]) == 1)
            i++;
        scanf("%*s");
        bl = i;
	
        sort(a, al);
        sort(b, bl);
	
        numberOfTimes(a, al, b, bl);
        return 0;
    }