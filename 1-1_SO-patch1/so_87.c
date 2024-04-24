    #include<stdio.h>
    #include<stdlib.h>
    int main(){
       int N,i,radius,diameter,count =0;
       char str[20];
    
       printf("Get the num : ");
    
       char buffer[64];
       fgets(buffer, 64, stdin);
       N = strtoul(buffer,NULL,10); 
       char color[N][20];
       
       printf("%d\n",sizeof(color));
       
       printf("Enter the mesage\n");
       
       for(i=0;i<N;i++){
          fgets(color[i],20,stdin);
          //fflush(stdin);
          while ((getchar()) != '\n');
       }
       for(i=0;i<N;i++){
          printf("%s\n",color[i]);
      }
      return 0;
    }