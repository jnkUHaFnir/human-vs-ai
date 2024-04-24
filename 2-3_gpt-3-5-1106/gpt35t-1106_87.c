printf("Get the num : ");
scanf("%d",&N);
getchar(); // or fflush(stdin);

printf("Enter the mesage\n");
for(i=0;i<N;i++){
   fgets(color[i],20,stdin);
}
