if((stringA=malloc(BUFSIZ))==NULL){
    printf("\n\tMEMORY ERROR\n\n");
    exit(1);
}
stringA=build_get_query(argv[1],page);  // Here you lose the reference to the memory just allocated
memset(stringA, 0, sizeof(stringA));
if((sstr=strstr(stringA,"<!DOCTYPE "))!=NULL){
    stringA=sstr;
}
close(sockfd);
free(stringA); // When done with it
