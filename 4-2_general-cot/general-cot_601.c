#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char *input(void)
{
    int n = 1;
    char *str = malloc(sizeof(char));
    if (str == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    
    *str = '\0';
    char *temp = str;
    
    while((*temp=getchar())!='\n')
    {
        n++;
        char *new_str = realloc(str, sizeof(char) * n);
        if (new_str == NULL) {
            printf("Memory allocation error\n");
            free(str);
            exit(1);
        }
        
        str = new_str;
        temp = str + n - 1;
    }
    
    return str;
}

int main(int argc, char const *argv[])
{
    char *str = input();
    printf("%s",str);
    free(str);
    return 0;
}
