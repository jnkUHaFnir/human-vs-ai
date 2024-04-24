#include <stdio.h>
#include <stdlib.h>

void findx(int x, int a, int tab[][3], int result[][3], int *k);
void print_result(int result[][3], int k);

int main(){
    int a;
    scanf("%d", &a);
    int tab[a][3];
    int (*result)[3] = malloc(sizeof(int[3]) * a);
    int k = 0;

    for(int i = 0; i < a; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &tab[i][j]);
        }
    }

    findx(0, a, tab, result, &k);
    if (k > 0) {
        print_result(result, k);
    } else {
        printf("no result\n");
    }

    free(result);
    return 0;
}

void findx(int x, int a, int tab[][3], int result[][3], int *k){
    for(int i = 0; i < a; i++){
        if(tab[i][0] == x){
            if(tab[i][2] == 0){
                result[*k][0] = tab[i][0];
                result[*k][1] = tab[i][1];
                result[*k][2] = tab[i][2];
                *k += 1;
                return;
            }
            else{
                result[*k][0] = tab[i][0];
                result[*k][1] = tab[i][1];
                result[*k][2] = tab[i][2];
                *k += 1;
                findx(tab[i][1], a, tab, result, k);
                break;  // Assuming only one continuation puzzle per step
            }
        }
    }
}

void print_result(int result[][3], int k){
    printf("%d\n", k);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
