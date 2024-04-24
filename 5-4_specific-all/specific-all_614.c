#include <stdio.h>
#include <stdlib.h>

int is_prime(int num){
    int cont, i;

    for(cont=2; cont<num; cont++){
        if(num % cont == 0){
            return 0; // Not a prime number
        }
    }
    return 1; // Prime number
}

int getNextPrime(int start){
    int num = start + 1;
    while(1){
        if(is_prime(num)){
            return num;
        }
        num++;
    }
}

int main(){
    int *v, n, cont;
    
    do{
        printf("Input an integer: ");
        scanf("%d", &n);
    } while (n <= 0);

    v = (int *)malloc(n *  sizeof(int));    

    v[0] = 2; // First prime number is 2
    for(cont=1; cont<n; cont++){
        v[cont] = getNextPrime(v[cont-1]);
    }

    for(cont=0; cont<n; cont++){
        printf("%d ", v[cont]);
    }

    free(v);
    return 0;
}
