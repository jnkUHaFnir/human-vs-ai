    int main(){
       int N,i,radius,diameter,count =0;
       printf("Get the Num: ");
       scanf("%d%*c",&N);
       char str[20];
       char color[N][20];
       printf("Enter the mesage\n");
       for(i=0;i<N;i++){
          scanf("%[^\n]%*c",color[i]);
       }
       for(i=0;i<N;i++){
          printf("%s",color[i]);
      }
      return 0;
    }