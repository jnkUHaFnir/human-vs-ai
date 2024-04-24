c
#include <stdlib.h>
#include <stdio.h>
void get(char **string){
    char *input = NULL;
    int result, index = 0;
    while (1) {
        result = getchar();
        if (EOF == result) { printf("\n"); break; }
        if ('\n' == result) break;
        char *temp = realloc(input , index + 2);
        if (NULL == temp) {
            perror("Could not increase memory for string");
            if (input) free(input);
            exit(1);
        }
        input = temp;
        input[index++] = (char) result;
    }
    if (input) {
        (input)[index] = '\0';
        *string = input;
    }
}
int main(void) {
    char *buff = NULL;
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