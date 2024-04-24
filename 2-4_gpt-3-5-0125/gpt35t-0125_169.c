#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    char line[100];
    char line1[100];
    char line2[100];
    
    f = fopen("textfile.txt", "r");
    
    if (!f) {
       printf("error");
       exit(1);
    } 
    
    int i = 0;
    while (1) {
        char ch = fgetc(f);
        
        if (ch == '\n' || ch == EOF) {
            line[i] = '\0'; // Null-terminate the line
            break;
        }
        
        line[i] = ch;
        i++;
    }
    
    strcpy(line1, line);
    
    i = 0;
    while (1) {
        char ch = fgetc(f);
        
        if (ch == '\n' || ch == EOF) {
            line[i] = '\0'; // Null-terminate the line
            break;
        }
        
        line[i] = ch;
        i++;
    }
    
    strcpy(line2, line);
    
    printf("1st line ==> %s\n", line1);
    printf("2nd line ==> %s\n", line2);

    fclose(f);
    
    return 0;
}
