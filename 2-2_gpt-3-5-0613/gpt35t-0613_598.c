#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert_to_16(char *characters, int n){

    char sub_buffer[3];
    char code[3];
    char *buffer = (char*)malloc(strlen(characters) * 2);
    memset(buffer, 0, strlen(characters) * 2); // Initialize buffer with zeroes
    for(int i=0; i < n; i++){
        strncpy(code, characters+i, 1);
        sprintf(sub_buffer, "%x", *code);
        strncat(buffer, sub_buffer, 2);
    } 
    return buffer;
}

// main() only for test
int main(){
    char param[] = "ABCDEFGHTUIKLL";
    printf("%s\n", param);
    int length = strlen(param);
    printf("%s\n", convert_to_16(param, length));
}
41424344454647485455494b4c4c
