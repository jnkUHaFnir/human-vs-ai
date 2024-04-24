#include <stdio.h>
#include <stdlib.h>

int prime(int num){
    static int j = 1; // Static variable to keep track of the last prime number found
    int cont,i,b;

    b=num;

    do{
        j++;
        i=0;
        for(cont=1;cont<j;cont++){
            if(j%cont == 0)
                i++;
        }
        if(i == 1){
            b--;
            return j;
        }
    } while (b > 0);

    return 0; // Return 0 if no prime number is found
}

int main(){
    int *v,n,cont;

    do{
        printf("Input an integer: ");
        scanf("%d",&n);
    } while (n <= 0);

    v = (int *)malloc(n *  sizeof(int));    

    for(cont=0;cont<n;cont++){
        v[cont] = prime(n);
    }

    for(cont=0;cont<n;cont++){
        printf("%d ",v[cont]);
    }

    free(v); // Don't forget to free the allocated memory

    return 0;
}
