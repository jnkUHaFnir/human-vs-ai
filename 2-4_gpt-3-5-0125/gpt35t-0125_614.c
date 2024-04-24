#include <stdio.h>
#include <stdlib.h>

int prime(int num){
    static int prev = 1; // Static variable to store previous prime number
    int i, j = prev + 1, is_prime;

    while (1) {
        is_prime = 1;
        for (i = 2; i <= j / 2; i++) {
            if (j % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            prev = j; // Update the static variable
            return j;
        }
        j++;
    }
}

int main(){
    int *v, n, cont;

    do{
        printf("Input an integer: ");
        scanf("%d", &n);
    } while (n <= 0);

    v = (int *)malloc(n *  sizeof(int));    

    for (cont = 0; cont < n; cont++){
        v[cont] = prime(n);
    }

    for (cont = 0; cont < n; cont++){
        printf("%d ", v[cont]);
    }

    free(v); // Don't forget to free the allocated memory

    return 0;
}
