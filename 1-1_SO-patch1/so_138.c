c
#include <stdlib.h>
#include <stdio.h>
void get(char **string){
    *string = NULL;
    int size = 1;
    int result;
    int i = 0;    
    while (1) {
        result = getchar();
        if (EOF == result) { printf("\n"); break; }
        if ('\n' == result) break;
        char *temp = realloc(*string , ++size);
        if (NULL == temp) {
            perror("Could not increase memory for string");
            if (*string) free(*string);
            exit(1);
        }
        *string = temp;
        (*string)[i] = (char) result;
        i++;
    }
    if (*string) (*string)[size - 1] = '\0';
}
int main(void) {
    char *buff;
    printf("String : ");
    get(&buff);
    if (buff) {
        printf("%s\n" , buff);
        free(buff);
    }
    return 0;
}
**Output**
none
$ ./main
String : a short string
a short string
$ ./main
String : input with EOF
input with EOF
**Note**
I do my best to handle error conditions, but I am not certain I caught everything.