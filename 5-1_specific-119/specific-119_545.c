if((stringA=malloc(BUFSIZ))==NULL){
    printf("\n\tMEMORY ERROR\n\n");
    exit(1);
}
stringA=build_get_query(argv[1],page);
if((write(sockfd,stringA,strlen(stringA)))<0){
    printf("\n\tERROR ON SEND\n\n");
}
memset(stringA, 0, sizeof(stringA));

while((tmpres=read(sockfd,stringA,BUFSIZ))>0){

    if((sstr=strstr(stringA,"<!DOCTYPE "))!=NULL){
        stringA=sstr;
    }
    if((sstr=strstr(stringA,"</html>"))!=NULL){
        strncpy(sstr+7,"\n",(BUFSIZ-strlen(stringA))+5);
    }
    fprintf(stdout,"%s",stringA);

}
if((stringA=malloc(BUFSIZ))==NULL){
    printf("\n\tMEMORY ERROR\n\n");
    exit(1);
}
char *getQuery = build_get_query(argv[1], page);
strcpy(stringA, getQuery);
free(getQuery); // Free memory allocated by build_get_query

if((write(sockfd,stringA,strlen(stringA)))<0){
    printf("\n\tERROR ON SEND\n\n");
}
memset(stringA, 0, BUFSIZ); // Reset buffer content

while((tmpres=read(sockfd,stringA,BUFSIZ))>0){

    if((sstr=strstr(stringA,"<!DOCTYPE "))!=NULL){
        stringA=sstr;
    }
    if((sstr=strstr(stringA,"</html>"))!=NULL){
        strncpy(sstr+7,"\n",(BUFSIZ-strlen(stringA))+5);
    }
    fprintf(stdout,"%s",stringA);

}
