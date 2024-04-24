    int main(void) {
        int i=0,j;
        char* string[100];
        char line[100];
        FILE *file; 
        file = fopen("patt", "r"); 
        while(fgets(line, sizeof(line), file)!=NULL) {//You missed the ()'s in the sizeof
            printf("%d %s",i, line);
            string[i]=line;
            i++;
        }