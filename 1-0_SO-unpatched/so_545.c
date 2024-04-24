    char readBuffer[BUFSIZ+1];
    if((stringA=malloc(BUFSIZ+1))==NULL){
        printf("\n\tMEMORY ERROR\n\n");
        exit(1);
    }
    stringA=build_get_query(argv[1],page);
    if((write(sockfd,stringA,strlen(stringA)))<0){
        printf("\n\tERROR ON SEND\n\n");
    }
    memset(readBuffer, 0, BUFSIZ+1);
    while((tmpres=read(sockfd,readBuffer,BUFSIZ))>0){
        if((sstr=strstr(readBuffer,"<!DOCTYPE "))!=NULL){
            readBuffer=sstr;
        }
        if((sstr=strstr(readBuffer,"</html>"))!=NULL){
            strncpy(sstr+7,"\n",(BUFSIZ-strlen(readBuffer))+5);
        }
        fprintf(stdout,"%s",readBuffer);
        memset( readBuffer, 0 , BUFSIZ+1 );
    }