#include <stdio.h>
#include <stdlib.h>

int is_prime(int num){
    int i;
    
    if(num < 2)
        return 0;

    for(i=2; i*i<=num; i++){
        if(num % i == 0)
            return 0;
    }

    return 1;
}

int main(){
    int *v, n, count = 0, number = 2;

    do{
        printf("Input the number of prime numbers you want to generate: ");
        scanf("%d", &n);
    } while (n <= 0);

    v = (int *)malloc(n * sizeof(int));    

    while(count < n){
        if(is_prime(number)){
            v[count] = number;
            count++;
        }
        number++;
    }

    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    
    free(v);

    return 0;
}
