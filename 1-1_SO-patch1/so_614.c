    bool prime2(int n)
    {
        for(int i = 2 ; i<n-1;i++)
            if( n% i == 0) return false;
        return true;
    }
    
    int main(){
        int *v,n,cont,cc=0;
        printf("Input range: 5\n ");
        scanf("%d",&n);
        v = (int *)malloc(n *  sizeof(int));    
    
        for(cont=2;cc<n;cont++){
            if( prime2(cont) )
            {
                v[cc] = cont;
                cc++;
            }        
        }
    
        for(cont=0;cont<n;cont++){
            printf("%d ",v[cont]);
        }
        
        delete v;
    }