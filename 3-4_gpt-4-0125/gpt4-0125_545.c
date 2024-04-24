if((stringA=malloc(BUFSIZ))==NULL){
    printf("\n\tMEMORY ERROR\n\n");
    exit(1);
}
// Previous allocation is lost, leading to a memory leak
stringA=build_get_query(argv[1],page);
query=malloc(strlen(host)+strlen(getpage)+strlen(USERAGENT)+strlen(tpl)-5);
query=malloc(strlen(host)+strlen(getpage)+strlen(USERAGENT)+strlen(tpl)-5 + 1); // or simply remove '-5' as it complicates understanding
if((sstr=strstr(stringA,"<!DOCTYPE "))!=NULL){
    stringA=sstr;
}
memset(stringA, 0, sizeof(stringA));
memset(stringA, 0, BUFSIZ); // or however many bytes you have actually allocated
