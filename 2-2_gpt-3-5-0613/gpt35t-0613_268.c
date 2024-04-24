#include <stdio.h>
#include <stdlib.h>

int main(void) { 
    int i=0,j; 
    char* string[100]; 
    char line[100]; 
    FILE *file; 
    file = fopen("patt", "r"); 
    while(fgets(line, sizeof line, file)!=NULL) { 
        printf("%d %s",i, line); 
        string[i]=(char*)malloc(strlen(line)+1); // allocate memory strcpy(string[i], line); i++; } for (j=0 ; j {
        printf("string[%d] %s",j, string[j]);
    }
    fclose(file); 
    return 0;
}