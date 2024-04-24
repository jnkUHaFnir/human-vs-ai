#include<stdio.h>

int findx(int x, int a, int tab[][3], int result[][3], int k);
int print_result(int result[][3], int k);

int main() {
  // code...
}
int result[a][3] = {0};  // result array with all elements initialized to 0
int findx(int x, int a, int tab[][3], int result[][3], int k) {
  int found = 0;
  for (int i = 0; i < a; i++) {
    if (tab[i][0] == x) {
      if (tab[i][2] == 0) {
        for (int m = 0; m < 3; m++) {
          result[k][m] = tab[i][m];
        }
        print_result(result, k + 1);
        found = 1;
        return 1;
      } else {
        for (int m = 0; m < 3; m++) {
          result[k][m] = tab[i][m];
        }
        if (findx(tab[i][2], a, tab, result, k + 1)) {
          found = 1;
        }
      }
    }
  }

  return found;
}
int print_result(int result[][3], int k) {
  printf("%d\n", k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
  return 0;
}
if (!findx(0, a, tab, result, 0)) {
  printf("no result\n");
}
#include<stdio.h>

int findx(int x, int a, int tab[][3], int result[][3], int k);
int print_result(int result[][3], int k);

int main() {
  int a;
  scanf("%d", &a);
  int tab[a][3];
  int result[a][3] = {0};

  for(int i = 0; i < a; i++){
    for(int j = 0; j < 3; j++){
      scanf("%d", &tab[i][j]);
    }
  }

  if (!findx(0, a, tab, result, 0)) {
    printf("no result\n");
  }

  return 0;
}

int findx(int x, int a, int tab[][3], int result[][3], int k) {
  int found = 0;
  for (int i = 0; i < a; i++) {
    if (tab[i][0] == x) {
      if (tab[i][2] == 0) {
        for (int m = 0; m < 3; m++) {
          result[k][m] = tab[i][m];
        }
        print_result(result, k + 1);
        found = 1;
        return 1;
      } else {
        for (int m = 0; m < 3; m++) {
          result[k][m] = tab[i][m];
        }
        if (findx(tab[i][2], a, tab, result, k + 1)) {
          found = 1;
        }
      }
    }
  }

  return found;
}

int print_result(int result[][3], int k) {
  printf("%d\n", k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
  return 0;
}
