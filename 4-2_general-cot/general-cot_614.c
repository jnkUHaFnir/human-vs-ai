#include <stdio.h>
#include <stdlib.h>

int is_prime(int num){
    if(num <= 1){
        return 0; // not prime
    }
    for(int i=2; i*i<=num; i++){
        if(num % i == 0){
            return 0; // not prime
        }
    }
    return 1; // prime
}

int main(){
    int n;
    
    do{
        printf("Input an integer: ");
        scanf("%d", &n);
    } while (n <= 0);

    int *v = (int *)malloc(n * sizeof(int));    

    int count = 0;
    for(int i=2; count<n; i++){
        if(is_prime(i)){
            v[count++] = i;
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }

    free(v);
    return 0;
}
