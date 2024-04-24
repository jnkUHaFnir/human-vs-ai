#include <stdio.h>

int isprime(unsigned long long n){
    unsigned long long i;
    for(i=2;i<n;i++){
        if((n%i)==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    unsigned long long n,i,lpf;
    scanf("%llu",&n);
    for(i=2;i<n;i++){
        if(n%i==0){
            if(isprime(i)==1){
                lpf=i;
            }
        }
    }
    printf("%llu",lpf);
    return 0;
}
