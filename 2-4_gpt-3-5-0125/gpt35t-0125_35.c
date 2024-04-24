#include<stdio.h>

int findx(int x, int a, int tab[a][3], int result[][3], int k);
int print_result(int result[][3], int k);

int main(){

    int a;
    scanf("%d", &a);//here i get how many puzzles i have
    int tab[a][3];//array for puzzles
    int result[a][3];//result array
    int k = 0;//this will help me track how many puzzles has my result array

    for(int i = 0; i < a; i++){//upload puzzles to array
        for(int j = 0; j < 3; j++){
            scanf("%d", &tab[i][j]);
        }
    }

    findx(0, a, tab, result, k);//start of recursion, because start has to be length 0

    return 0;
}

int findx(int x, int a, int tab[a][3], int result[][3], int k){//i am looking for puzzle with length x on start
    for(int i = 0; i < a; i++){
        if(tab[i][0] == x){//there i look for puzzles with x length at start
            if(tab[i][2] == 0){//if i find such puzzle i check if this is puzzle with edge length zero at the end
                for(int m = 0; m < 3; m++){//this for loop add to my result array last puzzle
                    result[k][m] = tab[i][m];
                }
                return print_result(result, k);//we will return result go to print_result function
            }
            else{//if i have puzzle with x length on the left and this is not puzzle which ends rectangle i add this puzzle
                    //to my result array and again look for puzzle with x equal to end length of puzzle i found there
                for(int m = 0; m < 3; m++){
                    result[k][m] = tab[i][m];
                }
                k += 1;
                return findx(tab[i][2], a, tab, result, k);
            }
        }
    }
    printf("no result");
    return 0;
}

int print_result(int result[][3], int k){
    printf("%d\n", k);//how many puzzles i have
    for(int i = 0; i < k; i++){//printing puzzles...
        for(int j = 0; j < 3; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");//...in separate lines
    }
    return 0;
}
