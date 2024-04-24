 #include<stdio.h>
 #include<stdlib.h>
 void print_result(int (*result)[3], int k){
     printf("%d", k);//how many puzzles i have
     printf("\n");
     for(int i = 0; i <= k; i++){//printing puzzles...
         for(int j = 0; j < 3; j++){
             printf("%d ", result[i][j]);
         }
         printf("\n");//...in separate lines
     }
 }
 void findx(int x, int a, int (*tab)[3], int (*result)[3], int k){//i am looking for puzzle with length x on start
     for(int i = 0; i < a; i++){
         if(tab[a][0] == x){//there i look for puzzles with x length at start
             if(tab[a][2] == 0){//if i find such puzzle i check if this is puzzle with edge length zero at the end
                 for(int m = 0; m < 3; m++){//this for loop add to my result array last puzzle
                     result[k][m] = tab[a][m];
                 }
                 return print_result(result, k);//we will return result go to print_result function
             }
             else{//if i have puzzle with x length on the left and this is not puzzle which ends rectangle i add this puzzle
                     //to my result array and again look for puzzle with x equal to end length of puzzle i found there
                 for(int m = 0; m < 3; m++){
                     result[k][m] = tab[a][m];
                     k += 1;
                     /** Increase size of result **/
                     int (*newptr)[3] = realloc(result, (k+1) * sizeof(int[3]));
                     if (newptr)
                         result = newptr;
                 }
                 findx(tab[a][2], a, tab, result, k);
             }
         }
     }
     printf("no result");
 }
 int main(){
     int a;
     scanf("%d", &a);//here i get how many puzzles i have
     int (*tab)[3] = malloc(sizeof(int[3]));//array for puzzles
     int (*result)[3] = malloc(a * sizeof(int[3]));//array for puzzles
     int k = 0;//this will help me track how many puzzles has my result array
     for(int i = 0; i < a; i++){//upload puzzles to array
         for(int j = 0; j < 3; j++){
             scanf("%d", &tab[i][j]);
         }
     }
     findx(0, a, tab, result, k);//start of recursion, because start has to be length 0
    //free(result);
    //free(tab);
 }
Note that I changed the tab and result types to `(*int)[3]`.  Due to order of operations,  we need parentheses here.  Because they are variable size, they require dynamic memory allocations.  In the interest of brevity and readability, I did not check the returned values of `malloc` or `realloc`.  In practice, you should be checking that the returned pointer is not `NULL`.  <s>Because we are using dynamic memory allocations, we should also use `free` if you plan on doing anything else with this program.  Otherwise,</s> it doesn't really matter because exiting the program will free the resources anyway.  You actually don't want to free.  because we are passing a pointer by value to `findx` and the `realloc` can change the address, it may come back with a different address.  Also, take note that I needed to `include <stdlib.h>` for the dynamic memory allocations.
**Additional Issues**
Your functions `print_results` and `findx` are not declared when you call them in `main`.  Your function either need to be above main or have "function prototypes" above `main`.  
In the `printf`s you do not need the `&`.  You do not want to send the address of the variable to `printf`.  You want to send what will actually be printed.
**Now what?**
The program still does not provide you with the correct results.  It simply outputs 0 as the result every time.  This should at least give you a starting point.  By changing this line in `print_results`:
for(int i = 0; i < k; i++){//printing puzzles...
to
for(int i = 0; i <= k; i++){//printing puzzles...
I was at least able to output `0 0 0`.  This seems more correct because if k is 0, we don't loop at all.