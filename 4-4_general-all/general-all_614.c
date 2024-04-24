#include <stdio.h>
#include <stdlib.h>

int is_prime(int num){
    int i;
    for(i = 2; i <= num/2; i++){
        if(num % i == 0){
            return 0; // Not a prime number
        }
    }
    return 1; // Prime number
}

int main(){
    int *v, n, cont, j = 2;

    do{
        printf("Input number of prime numbers to generate: ");
        scanf("%d", &n);
    } while (n <= 0);

    v = (int *)malloc(n * sizeof(int));

    for(cont = 0; cont < n;){
        if(is_prime(j)){
            v[cont] = j;
            cont++;
        }
        j++;
    }

    printf("First %d prime numbers are: ", n);
    for(cont = 0; cont < n; cont++){
        printf("%d ", v[cont]);
    }
    
    free(v);
    return 0;
}
