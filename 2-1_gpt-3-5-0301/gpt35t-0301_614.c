int is_prime(int num){
    int i;
    if(num < 2) return 0; // 0 and 1 are not prime
    for(i = 2; i <= num/2; i++){
        if(num % i == 0) return 0; // not prime
    }
    return 1; // prime
}

int prime(int last_prime, int offset){
    int i, num = last_prime + offset;
    while(!is_prime(num)) num++;
    return num;
}

int main(){
    int *v,n,cont,last_prime=1;

    do{
        printf("Input an integer: ");
        scanf("%d",&n);
    } while (n <= 0);

    v = (int *)malloc(n *  sizeof(int));    

    for(cont = 0; cont < n; cont++){
        last_prime = v[cont] = prime(last_prime, 1);
    }

    for(cont = 0; cont < n; cont++){
        printf("%d ",v[cont]);
    }

    free(v);
    return 0;
}
