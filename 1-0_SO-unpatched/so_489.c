    int main(void) {
    int i=0,j;
    char* string[100];
    char line[100];
    FILE *file; 
    file = fopen("patt", "r"); 
    while(fgets(line, sizeof(line), file)!=NULL) {//You missed the ()'s in the sizeof
        printf("%d %s",i, line);
        string[i]=malloc(strlen(line)+1); ///You need to allocate some memory to char* string[i] here
        if(string[i] == NULL)//Do a NULL check if malloc failed
          //Handle NULL here
        strncpy(string[i],line,strlen(line)+1);//Use strncpy to copy line into the malloced memory in string[i]
        i++;
    }