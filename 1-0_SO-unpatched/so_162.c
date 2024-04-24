    int *array, i, val, n, m;
    
    printf("Put in array size in the form of n-m where n is number of rows and m is number of columns: ");
    scanf("%d-%d", &n, &m);
    array = (int *) malloc(sizeof(int) * n * m);
    
    i = 0;
    while (i < n * m) {
      printf("Value for row: %d, column: %d: ", i / n + 1, i % n + 1);
      scanf("%d", &val);
      if (val > 99 || val < -99) continue;
      *(array + i) = val;
      i++;
    }
    
    for (i = 0; i < n * m; i++) {
      if (i > 0 && i % n == 0) printf("\n");
      printf("%d\t", *(array + i));
    }
    
    free(array);