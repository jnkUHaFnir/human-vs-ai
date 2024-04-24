#include<stdio.h>
#include<stdlib.h>

int main() {
  int n, j, k, item;
  printf("Enter size of array:\n");
  scanf("%d", &n);

  // Allocate memory for the array
  int *a = (int *) malloc((n + 1) * sizeof(int));
  
  for (j = 0; j < n; j++) {
    printf("Enter a[%d] element:\n", j);
    scanf("%d", &a[j]);
  }

  printf("Enter element to insert and position of element:\n");
  scanf("%d,%d", &item, &k);

  j = n - 1;
  while (j >= k - 1) {
    a[j + 1] = a[j];
    j = j - 1;
  }

  a[k - 1] = item;

  for (j = 0; j <= n; j++) {
    printf("%d\n", a[j]);
  }

  // Don't forget to free the memory allocated for the array
  free(a);

  return 0;
}
