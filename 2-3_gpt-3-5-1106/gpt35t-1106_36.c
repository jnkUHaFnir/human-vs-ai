int** result = (int**)malloc(a * sizeof(int*)); 
for (int i = 0; i < a; i++) {
    result[i] = (int*)malloc(3 * sizeof(int));
}
int findx(int x, int a, int tab[][3], int** result, int k);
int print_result(int** result, int k);
