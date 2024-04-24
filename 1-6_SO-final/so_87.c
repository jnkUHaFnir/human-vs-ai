     int main(){
       int N,i,radius,diameter,count =0;
       char str[20];
       char color[N][20];
       printf("Get the num : ");
       scanf("%d",&N);
    
       printf("Enter the mesage\n");
       for(i=0;i<N;i++){
          scanf(" %[^\n]",color[i]);
       }
       for(i=0;i<N;i++){
          printf("%s",color[i]);
      }
      return 0;
    }