#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int is_number(char *str) {
    for(int i =0; (i < strlen(str)) && (i != '\n') ; i++) {
        if(!isdigit(str[i]))
            return -1;
    }
    return 1;
}
int main()
{
    FILE *fp = fopen("input.txt", "r");
    char line[256];
    
    if(!fp) return -1;
    char **sentence;
    int i = 0;
    sentence = malloc(sizeof(char *));
    if(!sentence) return -1;
    while(fgets(line, 256, fp)) {
        char * token = strtok(line, " ");
        size_t len = 0;
        while(token != NULL) {
            if (is_number(token) != 1) {
                sentence[i] = realloc(sentence[i], len + 2 + strlen(token)); // +2 because 1 for null character and 1 for space character
                if (!sentence[i]) {
                    printf("cannot realloc\n");
                    return -1;
                }
                strcat(strcat(sentence[i], " "), token);
                len = strlen(sentence[i]);
            }
            token = strtok(NULL, " ");
        }
        i++;
        sentence = realloc(sentence, sizeof(char *) * i);
        if(!sentence) return -1;
    }
    
    for(int j = 0; j < i; j++) {
        printf("line[%d]: %s", j, sentence[j]);
    }
    
    for(int j = 0; j < i; j++) {
        free(sentence[i]);
    }
    free(sentence);
    return 0;
}
The input and output:
$cat input.txt
Example 1 sentence
Example sentence number xd 595 xd 49 lol
./test
line[0]:  Example sentence                                                                                                                                  
line[1]:  Example sentence number xd xd lol
  [1]: https://stackoverflow.com/questions/605845/do-i-cast-the-result-of-malloc